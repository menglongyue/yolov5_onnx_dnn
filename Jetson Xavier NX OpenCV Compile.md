# Jetson Xavier NX OpenCV编译

# 安装

## 一.检查已经安装的opencv是否开启CUDA加速

- 输入命令

```bash
sudo jtop
```

- 按数字6查看INFO页面，可以看到

```console
* OpenCV:   4.1.2   compiled CUDA:  NO
```

- 所以默认的 OpenCV 版本是不带 CUDA 加速的，无法充分利用 NX 的 GPU 性能

如果上面的compiled CUDA是NO，就需要卸载老版本，编译安装新版本。



### 卸载默认的 OpenCV 方法

```bash
sudo apt purge libopencv*
sudo apt autoremove
sudo apt update
```



## 二.编译安装流程

### (1)安装依赖库

- 输入以下命令

```bash
sudo apt install -y build-essential checkinstall cmake pkg-config yasm git gfortran
sudo apt update
sudo apt install -y libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev
sudo apt install -y libjpeg8-dev libjasper-dev libpng12-dev libtiff5-dev libavcodec-dev libavformat-dev libswscale-dev libdc1394-22-dev libxine2-dev libv4l-dev
sudo apt install -y libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgtk2.0-dev libtbb-dev libatlas-base-dev libfaac-dev libmp3lame-dev libtheora-dev libvorbis-dev libxvidcore-dev libopencore-amrnb-dev libopencore-amrwb-dev x264 v4l-utils
sudo apt install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
```

### (2)下载 OpenCV 和 opencv_contrib 源码（我会把下载好的一起打包发给你）

- 分别前往 [OpenCV](https://link.zhihu.com/?target=https%3A//github.com/opencv/opencv/releases) 和 [opencv_contrib](https://link.zhihu.com/?target=https%3A//github.com/opencv/opencv_contrib/releases) 的 github 仓库下载 Latest release 源码 ( 点击超链接跳转)
- 点击红框所标注的位置即可下载
- 注意 OpenCV 和 opencv_contrib 的版本要对应正确



### (3)编译和安装 OpenCV

- 将 opencv-4.5.5.tar.gz 和 opencv_contrib-4.5.5.tar.gz解压后放在同一文件夹

```bash
cd opencv-4.5.5
mkdir build
cd build
```

- 执行 cmake

```bash
cmake \
-DCMAKE_BUILD_TYPE=Release \
-DCMAKE_INSTALL_PREFIX=/usr/local \
-DOPENCV_ENABLE_NONFREE=1 \
-DBUILD_opencv_python2=1 \
-DBUILD_opencv_python3=1 \
-DWITH_FFMPEG=1 \
-DCUDA_TOOLKIT_ROOT_DIR=/usr/local/cuda \
-DCUDA_ARCH_BIN=7.2 \
-DCUDA_ARCH_PTX=7.2 \
-DWITH_CUDA=1 \
-DENABLE_FAST_MATH=1 \
-DCUDA_FAST_MATH=1 \
-DWITH_CUBLAS=1 \
-DOPENCV_GENERATE_PKGCONFIG=1 \
-DOPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-4.5.5/modules \
..
```

- make -j4 编译时间约为 2~3 小时

```bash
make -j4 # 四线程编译
```

- make 编译完成后，进行安装

```bash
sudo make install
```

- 至此，安装成功



## 三.检验安装结果

- 在 python3 中运行以下命令

```python
import cv2
cv2.__version__
```

- 正确打印出本次安装版本号即安装正确
- 在 jtop 中再次查看

![img](https://typora-images-1302473945.cos.ap-chengdu.myqcloud.com/images/202211041528020.webp)