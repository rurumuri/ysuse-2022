package com.al_1suyan.pojo;

import java.math.BigDecimal;

public class HomeCost implements java.io.Serializable {

    private int id;
    private String name;
    private BigDecimal money;
    private String date;
    private BigDecimal sum;
    private String remarks;

    public String getRemarks() {
        return remarks;
    }

    public void setRemarks(String remarks) {
        this.remarks = remarks;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public BigDecimal getMoney() {
        return money;
    }

    public void setMoney(BigDecimal money) {
        this.money = money;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public BigDecimal getSum() {
        return sum;
    }

    public void setSum(BigDecimal sum) {
        this.sum = sum;
    }


    @Override
    public String toString() {
        return "HomeCost [id=" + id + ", name=" + name + ", money=" + money + ", date=" + date + ", sum=" + sum + "]";
    }

    public HomeCost() {
    }

    public HomeCost(String name, BigDecimal money) {
        super();
        this.name = name;
        this.money = money;
    }

    public HomeCost(int id, String name, BigDecimal money, String date) {
        super();
        this.id = id;
        this.name = name;
        this.money = money;
        this.date = date;
    }

    public HomeCost(int id, String name, BigDecimal money, String date, BigDecimal sum) {
        super();
        this.id = id;
        this.name = name;
        this.money = money;
        this.date = date;
        this.sum = sum;
    }

    public HomeCost(int id, String name, BigDecimal money, String date, String remarks) {
        super();
        this.id = id;
        this.name = name;
        this.money = money;
        this.date = date;
        this.sum = sum;
        this.remarks = remarks;
    }

    public HomeCost(int id, String name, BigDecimal money, String date, BigDecimal sum, String remarks) {
        super();
        this.id = id;
        this.name = name;
        this.money = money;
        this.date = date;
        this.sum = sum;
        this.remarks = remarks;
    }
}
