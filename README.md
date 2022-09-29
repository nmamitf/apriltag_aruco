# apriltag_aruco
基于opencv的实现的Apriltag和aruco的识别，速度较快。

1、先对通过自适应阈值分割对图像进行二值化，然后再轮廓提取，删掉较小的轮廓。

2、对轮廓进行多边形拟合，这里采用的是approxPolyDP函数。如果是四边形，提取四个顶点。

3、四个顶点顺序可能是顺时针，或者逆时针。取第一个点与第三个点做直线，将第2个点代入直线方程，根据方程值的大小判断四个顶点的顺序，如果是逆时针就将其改成顺时针。

4、根据四个顶点对图像进行透射变化。每一个单元格占5个像素。
![image](https://user-images.githubusercontent.com/16878651/192954687-02f1ed20-50a9-4f01-87c7-ace97031b38b.png)
![image](https://user-images.githubusercontent.com/16878651/192955004-a187b134-a10c-4a39-9f7c-8b76e6cf453a.png)

5、对透射变化完的图像进行二值化，去掉最外面一圈，里面的为编码区。5x5的像素为一个小单元格，如果5x5中白色的多，为1，黑色的多就为0，形成一个二进制数字。
![image](https://user-images.githubusercontent.com/16878651/192955108-b3bdb2b7-89ef-49b0-89ab-6dfc75f832aa.png)

将上面二进制转成unsigned long long，然后拿unsigned long long的数到map里去找，如果有，就检测成功，顺便获取对应的ID号，若没有，对二进制图像进行旋转，再去map找。直到旋转了三次。
![image](https://user-images.githubusercontent.com/16878651/192955166-eb9459b6-0bdc-41cf-b973-3cd6a096ddb6.png)
![image](https://user-images.githubusercontent.com/16878651/192955363-4de1bbb3-e284-46fe-982c-57726ed2f9aa.png)


