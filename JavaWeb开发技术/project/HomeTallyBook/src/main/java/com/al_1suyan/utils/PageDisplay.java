package com.al_1suyan.utils;

import java.util.List;

// 页面JavaBean，实现记账本记账条目的显示列表的分页显示，每页显示具体账目数量可以设定
public class PageDisplay<E> {
    private int nowPage;                //当前显示的页码
    private List<E> element;            //分页显示的元素
    private final int maxNumOnePage = 8;  //一页只多显示8个
    private int maxOnePage;             //一个网页一共有多少的页数,这个在页面显示的时候得用
    private int size;                   //总共多少页,到时候尾页要用的东西
    //显示的页数就是以自己为中心，左右俩页

    public PageDisplay() {
        this.nowPage = 1;
        this.size = 0;
        this.maxOnePage = 0;
    }

    public PageDisplay(List<E> element) {
        this();
        this.element = element;
        this.size = ((element.size() - 1) / maxNumOnePage) + 1;
        this.maxOnePage = this.size >= 5 ? 5 : this.size;
    }

    public PageDisplay(int nowPage, List<E> element) {
        this.nowPage = nowPage;
        this.element = element;
        this.size = element.size() / maxNumOnePage;
        this.maxOnePage = this.size >= 5 ? 5 : this.size;
    }

    public int getNowPage() {
        return nowPage;
    }

    public void setNowPage(int nowPage) {
        this.nowPage = nowPage;
    }

    public List<E> getElement() {
        return element;
    }

    public int getMaxNumOnePage() {
        return maxNumOnePage;
    }

    public int getMaxOnePage() {
        return maxOnePage;
    }

    public int getSize() {
        return size;
    }
}
