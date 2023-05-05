#include "MusicPlayer.hpp"

MusicPlayer::MusicPlayer(string _filePath, float volume , float pitch)
    : m_loop(false)
    , filePath(_filePath)
{
    m_sound = new sf::Sound();
    m_buffer = new sf::SoundBuffer();
    loadSound();
}

void MusicPlayer::loadSound() {
    if (!m_buffer->loadFromFile(filePath)) {
        cout << "Error loading Music" << endl;
    }else {
        m_sound->setBuffer(*m_buffer);
    }

}

void MusicPlayer::setVolume(float volume) {
    m_sound->setVolume(volume);
}

void MusicPlayer::setPitch(float pitch) {
    m_sound->setPitch(pitch);
}

void MusicPlayer::setLoop(bool loop) {
    m_loop = loop;
    m_sound->setLoop(m_loop);
}

void MusicPlayer::play() {
    // m_sound->setBuffer(*m_buffer);
    // m_sound->setLoop(m_loop);
    m_sound->play();
}

void MusicPlayer::pause() {
    m_sound->pause();
}

void MusicPlayer::stop() {
    m_sound->stop();
}

bool MusicPlayer::isPlaying() const {
    return m_sound->getStatus() == sf::Sound::Playing;
}