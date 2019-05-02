#include "pyxelcore/audio.h"

#include "pyxelcore/music.h"
#include "pyxelcore/sound.h"

namespace pyxelcore {

Audio::Audio() {
  SDL_AudioSpec audio_spec;

  audio_spec.freq = AUDIO_SAMPLE_RATE;
  audio_spec.format = AUDIO_S16LSB;
  audio_spec.channels = 0;
  audio_spec.samples = AUDIO_BLOCK_SIZE;
  audio_spec.callback = callback;
  audio_spec.userdata = this;

  if (SDL_OpenAudio(&audio_spec, NULL) < 0) {
    // error
  }

  sound_bank_ = new Sound*[SOUND_BANK_COUNT];
  for (int32_t i = 0; i < SOUND_BANK_COUNT; i++) {
    sound_bank_[i] = new Sound();
  }

  music_bank_ = new Music*[MUSIC_BANK_COUNT];
  for (int32_t i = 0; i < MUSIC_BANK_COUNT; i++) {
    music_bank_[i] = new Music();
  }

  SDL_PauseAudio(0);
}

Audio::~Audio() {
  for (int32_t i = 0; i < SOUND_BANK_COUNT; i++) {
    delete sound_bank_[i];
  }
  delete[] sound_bank_;

  for (int32_t i = 0; i < MUSIC_BANK_COUNT; i++) {
    delete music_bank_[i];
  }
  delete[] music_bank_;
}

void Audio::callback(void* audio, uint8_t* stream, int len) {
  uint16_t* frame_data = reinterpret_cast<uint16_t*>(stream);
  int32_t frame_count = len / 2;

  for (int32_t i = 0; i < frame_count; i++) {
    frame_data[i] = 0;
  }
}

void Audio::PlaySound(int32_t channel, int32_t sound_index, bool loop) {
  //
}

void Audio::PlayMusic(int32_t music_index, bool loop) {
  //
}

void Audio::StopPlaying(int32_t channel) {
  //
}

}  // namespace pyxelcore
