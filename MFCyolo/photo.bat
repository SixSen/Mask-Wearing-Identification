
cd /d .\darknet-master\build\darknet\x64

 darknet.exe detector test data/KD.data cfg/yolov3-KD.cfg_test backup/yolov3-KD_last.weights %1 -thresh 0.2