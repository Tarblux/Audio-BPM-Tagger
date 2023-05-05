# Audio-BPM-Tagger

I make instrumentals in my free time so I often download audio samples that lack the correct BPM information. This makes it difficult to integrate them into my projects seamlessly. Instead of manually searching for the BPM on getsongbpm.com and renaming files, I decided to create a program that automatically detects and renames my audio files. This has significantly improved my workflow speed, allowing me to focus on making music.

This program uses Essentia, a powerful open-source library for audio analysis and processing, to extract the BPM (beats per minute) value from an audio file. The BPM value is then used to generate a new filename that includes the BPM information. This eliminates the need for manual BPM detection and renaming, saving valuable time and effort.

With this program, I can easily organize my audio samples by BPM and quickly integrate them into my projects. It's a simple but powerful tool that has greatly improved my music production workflow.


## Prerequisites

To run this code, you need to have Essentia installed on your system. You can install Essentia via pip:

```
pip install essentia
```

## Usage

1. Modify the `foldername` variable in the `main` function to point to the path of your audio files.
2. Run the code.

The BPM values of each audio file will be printed to the console.

## Output

The `generate_new_filename` function can be used to generate a new filename that includes the BPM value in the format `original_filename_bpm.extension`. You can modify this function to suit your needs.

## References

- Essentia: http://essentia.upf.edu/

## FUTURE PLANS

As a part of continuous improvement and development, I plan to add a graphical user interface to this project. This will provide a more user-friendly experience, enabling users to select and load audio files more easily, and view the extracted information in a more intuitive way.

In addition, I aim to expand the functionality of the program by incorporating the capability to detect the key of an audio file. By doing so, users will have more comprehensive information about the audio samples they are working with, enabling them to better integrate them into their projects.
