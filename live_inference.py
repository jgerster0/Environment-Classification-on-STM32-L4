import cv2
import serial
import threading
import numpy as np
import sys
import time
import sounddevice as sd
import numpy as np



class_names = ['air_conditioner', 'car_horn', 'children_playing', 'dog_bark', 'drilling', 'engine_idling', 'gun_shot', 'jackhammer', 'siren', 'street_music']


def parse_input(input_string):
    global count
    parts = input_string.split()
    #print(parts)
    try:
        if parts[0] == 'ack':
            if count == 0:
                mode = "tflite" if parts[2] == "1" else "cubeai"
                print(f"mode: {mode}")
            print(f"{count}. Filling up frames, MFCC Preprocessing: {(int(parts[1])/ 80000000):.4f}s")
        if parts[0] in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]:
            if float(parts[1]) < 0.1:
                print(f"{count}. Unsure, Inference: {(int(parts[2])/ 80000000):.4f}s")
            else:
                print(f"{count}. Prediction: {class_names[int(parts[0])]}, Confidence: {parts[1]}, Inference: {(int(parts[2])/ 80000000):.4f}s")
    except:
        print("Catch")
        print(parts)
    count += 1


def preprocess_frame(frame):

    return frame






latest_frame = None
frame_lock = threading.Lock()

count = 0



def audio_capture_thread(camera_index=0):
    """
    stream from microphone.
    """
    global latest_frame
    
    #test streaming
    """
    while True:
        # Create  2048 random int16 values
        with frame_lock:
            latest_frame = np.random.randint(-128, 127, size=2048, dtype=np.int8).tobytes()
    """
    
  
    

    def callback(indata, frames, time, status):
        global latest_frame
        if status:
            print("Stream status:", status)
        with frame_lock:
            latest_frame = indata.copy().astype(np.float32).tobytes()  

    # Start stream from mic
    with sd.InputStream(samplerate=16000,
                        channels=1,
                        dtype='float32',  
                        blocksize=1024,
                        callback=callback):
        while True:
            time.sleep(0.1)  # keep thread alive
    
    



def serial_read_thread(port='/dev/ttyACM0', baudrate=115200):

    #test data
    #test_wav_input2 = np.load("/test_wavs/rec_siren.npy").astype(np.float32)/ 32768.0
    #test_wav_input2 = np.load("/test_wavs/rec_jackhammer3.npy").astype(np.float32)/ 32768.0
    #test_wav_input2 = np.load("/test_wavs/rec_dog3.npy").astype(np.float32)/ 32768.0



    global latest_frame
    global count
    ser = serial.Serial(port, baudrate, timeout=None)
    print("Serial port opened:", ser.name)
    flag= False
    while True:
        # Read line 
        line = ser.readline().decode('utf-8').rstrip('\n')
        if "Waiting" in line:
            count = 0
            print("Starting UrbanSound8k Live Demo - Inference @ 80 MHz")
            flag = True
        else:
            parse_input(line)


        if flag:

            with frame_lock:

                #test data
                """
                time.sleep(1012/16000)

                if count + 1024 > len(test_wav_input2):
                    print("End of test data reached.")
                    break  # Exit or wrap around

                frame = test_wav_input2[count:count + 1024]
                count += 1024

                # Convert to raw bytes
                data = frame.astype(np.float32).tobytes()
                """



                
                if latest_frame is not None:
                    data = latest_frame
                    
                else:
                    # If no frame yet, skip
                    continue
                
            # Send data
            ser.write(data)
            ser.flush()

     

def main(port='/dev/ttyACM0', baudrate=115200, camera_index=0):
    ser_thread = threading.Thread(target=serial_read_thread, 
                                  kwargs={'port': port, 'baudrate': baudrate},
                                  daemon=True)
    ser_thread.start()

    audio_capture_thread(camera_index=camera_index)

    # Block main thread 
    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        print("\nInterrupted by user.")
    

if __name__ == "__main__":
    

    port = "/dev/tty.usbmodem1203"
    baudrate = 115200


    if len(sys.argv) > 1:
        port = sys.argv[1]
    if len(sys.argv) > 2:
        baudrate = int(sys.argv[2])

    main(port=port, baudrate=baudrate)