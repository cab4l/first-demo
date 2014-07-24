#include <cstring>

#include <dumb.h>

#include "mod_music.h"

#define SAMPLES_PER_SEC 65536

ModMusic::ModMusic()
    : module_(NULL), player_(NULL)
{}

ModMusic::~ModMusic()
{
    close();
    dumb_exit();
}

bool ModMusic::openFromMemory(const char *data, long size)
{
    close();
    module_ = dumb_read_xm_quick(dumbfile_open_memory(data, size));

    if (module_ != NULL)
    {
        initialize(NB_CHANNELS, SAMPLING_RATE);
        return true;
    }

    return false;
}

sf::Time ModMusic::getDuration() const
{
    return sf::seconds(static_cast<float>(duh_get_length(module_) / SAMPLES_PER_SEC));
}

void ModMusic::close()
{
    if (player_ != NULL)
    {
        duh_end_sigrenderer(player_);
        player_ = NULL;
    }
    if (module_ != NULL)
    {
        unload_duh(module_);
        module_ = NULL;
    }
}

void ModMusic::onSeek(sf::Time time_offset)
{
    long position = static_cast<long>(time_offset.asSeconds() * SAMPLES_PER_SEC);
    player_ = duh_start_sigrenderer(module_, 0, NB_CHANNELS, position);
}

bool ModMusic::onGetData(Chunk &data)
{
    float delta = float(SAMPLES_PER_SEC) / SAMPLING_RATE;

    duh_render(player_, 16, 0, 1.0f, delta, BUFFER_SIZE / 2, samples_);

    data.samples = samples_;
    data.sampleCount = BUFFER_SIZE;
    return true;
}
