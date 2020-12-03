# Mask-Wearing-Identification

效果展示：https://www.bilibili.com/video/BV19t4y117FL/

由于本软件需要基于CUDA加速，所以需要运行计算机提前安装好CUDA以及cuDNN，并且需要自行编译Darknet后才能运行。

## 环境要求

1. 安装CUDA以及cuDNN

   CUDA下载地址：https://developer.nvidia.com/cuda-downloads

   cuDNN下载地址：https://developer.nvidia.com/cudnn

2. 安装Microsoft VS2015

3. 下载OpenCV 4.1.0

   其他版本理论上也可以，但需要更改稍后需要编译的项目中的文件名

4. 修改 .\MFCyolo\darknet-master\build\darknet\darknet.vcxproj

   使用搜索CUDA，将文件中28处CUDA版本改为计算机已经安装的版本。

![img](https://raw.githubusercontent.com/SixSen/PicGo/img/clip_image002.jpg)

5. 打开 .\MFCyolo\darknet-master\build\darknet\darknet.sln文件并进行以下配置

   >​       
   >
   >Step 1：OpenCV环境变量配置 我的电脑--->属性--->高级系统设置--->高级--->环境变量--->系统变量--->Path--->编辑，将OpenCV安装目录的bin目录添加进去，记得加上 分号，本人电脑上的路径为：D:\opencv\build\x64\vc14\bin
   >
   >​      
   >
   > Step 2：VS2015中配置：**包含目录** + **库目录** + **链接器**
   >
   >![img](https://raw.githubusercontent.com/SixSen/PicGo/img/20200601191907.png)
   >
   >​       
   >
   >**(1)** **包含目录** **配置**：
   >
   >​       “包含目录”：
   >
   >​       （1）OpenCV安装目录下的...\include目录
   >
   >​       （2）OpenCV安装目录下的...\include\opencv目录
   >
   >​       （3）OpenCV安装目录下的...\include\opencv2目录
   >
   >
   >
   >**(2)** **库目录** **配置**：
   >
   >​       具体操作与 “包含目录”的配置类似，只是添加的路径不同而已。
   >
   >​       “库目录”：OpenCV目录下的...x64\vc14\lib(VS2015应选择vc14，如果是其他版本VS的话选择对应的文件夹)
   >
   >![img](https://raw.githubusercontent.com/SixSen/PicGo/img/clip_image002.png)
   >
   >​       
   >
   > **(3)** **链接器** **配置：**
   >
   >​       将OpenCV安装目录下的库 的名字添加进来即可。
   >
   >​       如：opencv_world410.lib
   >
   >![img](https://raw.githubusercontent.com/SixSen/PicGo/img/20200601192104.png)
   >
   >

6. 最后点击**生成选项中**的**生成darknet**

   如果生成成功的话打开.\MFCyolo\darknet-master\build\darknet\x64会有一个darknet.exe文件。

   

## 使用方法

1. 软件分为32位与64位版本，分别在 .\Release与.\x64\Release中。双击"MFCyolo.exe"就可以开始使用。

2. 如有使用上的问题请联系我 zhangximeng1212@foxmail.com

## 源文件结构

**Darknet文件夹**：.\MFCyolo\darknet-master

**names文件**：.\MFCyolo\darknet-master\build\darknet\x64\data\KD.names

**训练集文件**：.\MFCyolo\darknet-master\build\darknet\x64\data\train_images

**测试集文件**：.\MFCyolo\darknet-master\build\darknet\x64\data\val_images

**cfg文件**：

.\MFCyolo\darknet-master\build\darknet\x64\cfg\yolov3-KD.cfg_train(训练用)

.\MFCyolo\darknet-master\build\darknet\x64\cfg\yolov3-KD.cfg_test（测试用）
