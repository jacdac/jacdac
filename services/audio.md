# Audio

    identifier: 0x1f9cdb36
    camel: audio
    status: experimental
    group: sound

Receive an uncompressed byte stream of audio data to store in the buffer and play when requested.

# Registers

    rw sample_rate: u32 Hz @ 0x80

The sample rate for the audio stream.

    const max_sample_rate: u32 Hz @ 0x180

The maximum sample rate supported.

    rw bits_per_sample: u8 @ 0x81

The number of bits per sample for the audio stream.

    const max_bits_per_sample: u8 @ 0x181

The maximum number of bits per sample supported.

    rw volume: u0.8 @ 0x82

The volume for the audio stream, between 0 and 1.

    const buffer_size: u32 B @ 0x182

The maximum size of the audio buffer in bytes.

    ro playing: bool @ 0x183

Whether the audio stream is currently playing.

# Commands

    packed command load_audio @ 0x80 {
        start_playing: bool
        buffer: pipe
    }

Load data into the buffer. If `start_playing` is set to true, the audio will play immediately.

    command play @ 0x81 { }

Start playing the audio from the buffer.

    command stop @ 0x82 { }

Stop playing the audio.
