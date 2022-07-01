--- Dependencies ---
To use python script you need install opencv first.

--- Configure script ---
VIDEO_NAME -> Video file name you want to convert to materials
IMAGE_OUT_PATH -> Folder where you want store generated images.
MATERIAL_OUT_PATH -> Folder where you want store generated materials file
IMAGE_TARGET_SIZE -> Scale every frame to this size (None - if you don't want to do it)
IMAGE_FORMAT -> Format of image (jpg, png)
MATERIAL_TAG -> Every material name has unique id like: "MATERIAL_TAG/MATERIAL_NAME"

--- Run script ---
python3 main.py
materials -> Folder with your materials.
pictures -> Folder with your pictures.
Both these folders must be place in your model folder.

fps.txt -> How much video has FPS.
For example:
If your video has 25 fps, that mean you should change material picture every 1000ms(1sec)/25fps=~40ms to make your video smooth.

script.txt -> All context must be copy to your model .sdf to <material> tag.
For example:
<visual name="visual_name">
<plugin name="demo_change_plugin" filename="libDisplayChangePlugin.so"></plugin>
...
<material>
HERE PAST script.txt
</material>
</visual>

demo_change_plugin is a gazebo plugin that provide possibility to play "video" in gazebo.
(It change picture every XX ms)
