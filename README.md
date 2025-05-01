# video_capture_h264
Video capture using default camera and OpenCV. Grabs frames from the default camera, scales them, inverts colors, flips both axes, and writes to an H.264-encoded MP4.

## Requierments: 

- C++ compiler with C++17 support
- Visual Studio Code
- Visual Studio 17 2022 generator
- [OpenCV](https://opencv.org/) built with FFmpeg & x264 support
- [CMake](https://cmake.org/) ≥ 3.10.0
- VSC extensions for CMake, C/C++
- Download https://github.com/cisco/openh264/releases/tag/v1.8.0. - exactly this version!
- Make sure openh264-1.8.0-win64.dll is in opencv\build\x64\vc16\bin and opencv_videoio_ffmpeg4110_64.dll is in video_capture_h264\out\build\mypreset.  opencv_videoio_ffmpeg4110_64.dll is located opencv\build\x64\vc16\bin
- Put the tasks.json file in your .vscode folder

## Building:

- Build it using the build and run from the CMake extension
- ![grafik](https://github.com/user-attachments/assets/80bbf7cc-fc0b-459a-b47d-88234e6d1607)

