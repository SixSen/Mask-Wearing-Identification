
cd /d ..\MFCyolo\darknet-master\build\darknet\x64

 darknet.exe detector demo data/KD.data cfg/yolov3-KD.cfg_test backup/yolov3-KD_last.weights -thresh 0.2 %1