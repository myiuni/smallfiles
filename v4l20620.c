#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <fcntl.h>

#include <linux/videodev2.h>

#define COUNT 5

int main()
{
	int fd,i;
	unsigned char *datas[COUNT];
	int ret;
	fd = open("/dev/video0", O_RDWR);
	if (-1 == fd) {
		perror("open /dev/video0");
		exit(1);
	}

	struct v4l2_format fmt;
	fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	fmt.fmt.pix.width = 1920;
	fmt.fmt.pix.height = 1080;
	fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;

	ret = ioctl(fd, VIDIOC_S_FMT,&fmt);
	if (-1 == ret) {
		perror("ioctl VIDIOC_S_FMT");
		close(fd);
	}
	ret = ioctl(fd, VIDIOC_G_FMT, &fmt);
	if (fmt.fmt.pix.pixelformat == V4L2_PIX_FMT_YUYV)
		printf("ioctl VIDIOC_S_FMT successful\n");
	else
		printf("ioctl VIDIOC_S_FMT failed\n");
	printf("VIDIOC_G_FMT is very important!\n");

	struct v4l2_requestbuffers reqbuf;
	reqbuf.count = COUNT;
	reqbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	reqbuf.memory = V4L2_MEMORY_MMAP;

	printf("v4l2_requbuf success!\n");
	ret = ioctl(fd, VIDIOC_REQBUFS, &reqbuf);
	if (-1 == ret)
		perror("ioctl VIDIOC_REQBUF");

	struct v4l2_buffer buff;
	buff.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	buff.memory = V4L2_MEMORY_MMAP;
	printf("v4l2_buffer success!\n");
	for (i=0; i<COUNT; i++)
	{
		buff.index = i;
		ret = ioctl(fd, VIDIOC_QUERYBUF, &buff);
		if (-1 == ret)
			printf("query buffer error\n");
		printf("buf[%d]: len = %d offset: %d\n", i, buff.length, buff.m.offset);
	
	printf("loop success!\n");
	datas[i] = mmap(NULL, buff.length, PROT_READ, MAP_SHARED, fd, buff.m.offset);
	printf("mmap success!\n");
	if (MAP_FAILED == datas[i]) {
		perror("mmap failed");
		exit(1);
	}
	ret = ioctl(fd, VIDIOC_QBUF, &buff);
	printf("qbuf success!\n");
	}

	int on = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	ret = ioctl(fd, VIDIOC_STREAMON, &on);
	printf("stream on success!\n");
	if (-1 == ret) {
		perror("ioctl VIDIOC_STREAMON");
		exit(1);
	}
	ret = ioctl(fd, VIDIOC_DQBUF, &buff);
	printf("dqbuf success!\n");

	FILE *fl;
	fl = fopen("./abc.yuyv", "w");
	printf("open success!\n");
	if (NULL == fl)
		perror("open error");
	printf("why error there?\n");
	fwrite(datas[buff.index], buff.bytesused, 1, fl);
	printf("Write success!\n");
	printf("==========\n");
	fclose(fl);
	close(fd);
	return 0;
}
