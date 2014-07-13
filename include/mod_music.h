#ifndef MOD_MUSIC_H
#define MOD_MUSIC_H

#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class DUH;
class DUH_SIGRENDERER;

/**
 * A wrapper around the DUMB library to enable playback of module files using SFML
 */
class ModMusic : public sf::SoundStream
{
    public:
        /**
         * Construct a new ModMusic instance.
         */
        ModMusic();

        /**
         * Destroy this ModMusic instance.
         */
        ~ModMusic();

        /**
         * Read music from an audio file.
         *
         * @param filename the file to load
         * @return true if the music was succesfully loaded, false otherwise
         */
        bool openFromFile(const std::string &filename);

        /**
         * Get the total duration of the music.
         * @return a sf::Time instance representing the total duration
         */
        sf::Time getDuration() const;
    private:
        /**
         * The audio sampling rate.
         */
        static const int SAMPLING_RATE = 44100;

        /**
         * The audio buffer size.
         */
        static const int BUFFER_SIZE = SAMPLING_RATE;

        /**
         * The number of audio channels.
         */
        static const int NB_CHANNELS = 2;

        /**
         * Close the audio track.
         */
        void close();

        /**
         * Handle new data.
         * @return true if successful
         */
        bool onGetData(Chunk &data);

        /**
         * Seek to a given time.
         */
        void onSeek(sf::Time time_offset);

        /**
         * Samples.
         */
        sf::Int16 samples_[BUFFER_SIZE];

        /**
         * The DUMB audio module.
         */
        DUH *module_;

        /**
         * The DUMB audio renderer.
         */
        DUH_SIGRENDERER *player_;
};

#endif
