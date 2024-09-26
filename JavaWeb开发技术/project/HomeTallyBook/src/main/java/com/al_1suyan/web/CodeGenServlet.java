package com.al_1suyan.web;

import javax.imageio.ImageIO;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Random;

@WebServlet("/code")
public class CodeGenServlet extends HttpServlet {
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //定义图片的长和高
        int height = 20;
        int width = 60;
        //生成图像缓冲区
        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        //绘图工具
        Graphics graphics = image.getGraphics();
        //绘制矩形
        graphics.setColor(getRandColor());
        //绘制矩形背景 前俩个参数是 x y的坐标
        graphics.fillRect(0, 0, width, height);
        //设置文字颜色 为白色
        graphics.setColor(Color.WHITE);
        String yzm = "";
        //生成四个随机数并且画在图片上
        for (int i = 1; i <= 4; i++) {
            int number = new Random().nextInt(10);
            yzm += number;
            graphics.drawString(number + "", 10 * i, 10);
        }
        //将验证码放到session中
        HttpSession session = req.getSession();
        session.setAttribute("code", yzm);
        //将验证码输出到客户端
        ImageIO.write(image, "jpg", resp.getOutputStream());
    }

    // 获取随机颜色
    private Color getRandColor() {
        int red = new Random().nextInt(255);
        int green = new Random().nextInt(255);
        int blue = new Random().nextInt(255);
        return new Color(red, green, blue);
    }
}

