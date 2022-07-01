# GazeboVideoPlayer
Play video in gazebo simulation.
![](https://github.com/SpyroSoft-Synergy/GazeboVideoPlayer/blob/dev/example/final_result.gif)

Plugin
-
Gazebo plugin -> Change model material every XX ms.
#### Build
- `colcon build`
- `source setup.bash`

Video converter
-
Python script -> Convert `.mp4` video to separete frames (jpg or png) and create gazebo material files.
#### Build
- `python3 video_converter.py`

Example
-
Example world with display.
#### Build
- Build plugin
- Copy `video_converter.py` to `example` folder
- Run `python3 video_converter.py`
- Copy all content of `script.txt` into `display_model/display.sdf` to line 17
- Being in `example` folder run: `gazebo test_world.world`

More information
-
For more information check `README.txt` in folders.
