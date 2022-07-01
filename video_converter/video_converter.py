import os
import cv2

VIDEO_NAME = "test_video.mp4"
IMAGE_OUT_PATH = "pictures/"
MATERIAL_OUT_PATH = "materials/"
IMAGE_TARGET_SIZE = (480, 480) # If you don't want to scale picture set it to None
IMAGE_FORMAT = "jpg"
MATERIAL_TAG = "Demo"

if __name__ == "__main__":
    vid = cv2.VideoCapture(VIDEO_NAME)
    fps = vid.get(cv2.CAP_PROP_FPS);
    counter = 0
    material_counter = 1
    os.makedirs(IMAGE_OUT_PATH, exist_ok=True)
    os.makedirs(MATERIAL_OUT_PATH, exist_ok=True)
    all_material_name = []
    while(vid.isOpened()):
        ret,frame = vid.read()
        if ret == True:
            # Save picture
            picture_id = "pic" + str(material_counter)
            picture_name = picture_id + "." + IMAGE_FORMAT
            image_path = os.path.join(IMAGE_OUT_PATH, picture_name)
            if IMAGE_TARGET_SIZE != None:
                frame = cv2.resize(frame, IMAGE_TARGET_SIZE, interpolation = cv2.INTER_AREA)
            cv2.imwrite(image_path, frame)
            # Save material info
            material_file_name = picture_id + ".material"
            all_material_name.append(MATERIAL_TAG + "/" + picture_id)
            material_data = f"material {all_material_name[-1]}\n"\
                "{\n"\
                "\ttechnique\n"\
                "\t{\n"\
                "\t\tpass\n"\
                "\t\t{\n"\
                "\t\t\ttexture_unit\n"\
                "\t\t\t{\n"\
                f"\t\t\t\ttexture ../{image_path}\n"\
                "\t\t\t}\n"\
                "\t\t}\n"\
                "\t}\n"\
                "}\n"

            material_path = os.path.join(MATERIAL_OUT_PATH, material_file_name)
            material_file = open(material_path, "w")
            material_file.write(material_data)
            material_file.close()
            material_counter += 1
        else:
            break
        counter = 0
    vid.release()
    cv2.destroyAllWindows()
    fps_file = open("fps.txt", "w")
    fps_file.write(f"{fps}")
    fps_file.close()

    script_file = open("script.txt", "w")
    for material in all_material_name:
        script_file.write("<script>\n")
        script_file.write(f"\t<uri>{MATERIAL_OUT_PATH}</uri>\n")
        script_file.write(f"\t<name>{material}</name>\n")
        script_file.write("</script>\n")
    script_file.close()