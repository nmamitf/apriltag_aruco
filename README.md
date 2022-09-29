# apriltag_aruco
基于opencv的实现的Apriltag和aruco的识别，速度较快。

1、先对通过自适应阈值分割对图像进行二值化，然后再轮廓提取，删掉较小的轮廓。

2、对轮廓进行多边形拟合，这里采用的是approxPolyDP函数。如果是四边形，提取四个顶点。

3、四个顶点顺序可能是顺时针，或者逆时针。取第一个点与第三个点做直线，将第2个点代入直线方程，根据方程值的大小判断四个顶点的顺序，如果是逆时针就将其改成顺时针。

4、根据四个顶点对图像进行透射变化。每一个单元格占5个像素。

![image-20220929135627440](C:\Users\Zener\AppData\Roaming\Typora\typora-user-images\image-20220929135627440.png)

![image-20220929135657262](C:\Users\Zener\AppData\Roaming\Typora\typora-user-images\image-20220929135657262.png)

5、对透射变化完的图像进行二值化，去掉最外面一圈，里面的为编码区。5x5的像素为一个小单元格，如果5x5中白色的多，为1，黑色的多就为0，形成一个二进制数字。

![image-20220929140147864](C:\Users\Zener\AppData\Roaming\Typora\typora-user-images\image-20220929140147864.png)   

![image-20220929140515068](C:\Users\Zener\AppData\Roaming\Typora\typora-user-images\image-20220929140515068.png)编码区域图。![image-20220929140740539](C:\Users\Zener\AppData\Roaming\Typora\typora-user-images\image-20220929140740539.png)



将上面二进制转成unsigned long long，然后拿unsigned long long的数到map里去找，如果有，就检测成功，顺便获取对应的ID号，若没有，对二进制图像进行旋转，再去map找。直到旋转了三次。

![image-20220929141334113](C:\Users\Zener\AppData\Roaming\Typora\typora-user-images\image-20220929141334113.png)

