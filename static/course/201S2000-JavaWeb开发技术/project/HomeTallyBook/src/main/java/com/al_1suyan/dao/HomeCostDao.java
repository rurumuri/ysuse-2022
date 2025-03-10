package com.al_1suyan.dao;

import com.al_1suyan.pojo.HomeCost;
import com.al_1suyan.utils.DBUtils;

import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class HomeCostDao {

    private int uid;
    private String username;

    public HomeCostDao(int uid) {
        this.uid = uid;
    }

    public HomeCostDao(String username) {
        //this.uid = uid;
        this.username = username;
    }

    public int updateSql(String sql) {
        Connection conn = DBUtils.getConn();//��ȡ���Ӷ���
        Statement state = null;
        try {
            state = conn.createStatement();
            return state.executeUpdate(sql);
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            DBUtils.close(state, conn);
        }
        return -1;
    }

    public int deleteByUserName(String username) {
        String sql = String.format("delete from user where username='%s'", username);
        return updateSql(sql);
    }

    //���
    public int add(HomeCost homecost, int uid) {
        String sql = "insert into record(name,money, user_id) values('" + homecost.getName()
                + "','" + homecost.getMoney() + "','" + uid + "')";
        return updateSql(sql);
    }

    public int delete(int id) {
        String sql = "delete from record where id='" + id + "'";
        return updateSql(sql);
    }

    public int update(HomeCost homecost) {
        //update��䣬����update ���� set �ֶ�1 = 'ֵ1',�ֶ�2 = 'ֵ2'where id = 'ֵ3';
        String sql;

        if (homecost.getRemarks() != null) {
            sql = String.format("update record set name='%s',money='%s',remarks='%s' where id='%d' and user_id='%d'", homecost.getName(), homecost.getMoney(), homecost.getRemarks(), homecost.getId(), uid);
        } else {
            sql = String.format("update record set name='%s',money='%s' where id='%d' and user_id='%d'", homecost.getName(), homecost.getMoney(), homecost.getId(), uid);
        }
        return updateSql(sql);
    }

    public List<HomeCost> query(String keyword) {
        String sql = "select * from record WHERE user_id=" + uid + " and (name LIKE '%" + keyword + "%' OR money LIKE '%" + keyword
                + "%'OR date LIKE '%" + keyword + "%')";
        System.out.println(sql);
        List<HomeCost> list = new ArrayList<>();
        Connection conn = DBUtils.getConn();
        Statement state = null;
        ResultSet rs = null;
        try {
            state = conn.createStatement();
            rs = state.executeQuery(sql);
            while (rs.next()) {
                int id = rs.getInt("id");//��ȡ��ѯ����е�id
                String name = rs.getString("name");//��ȡ��ѯ����е�name
                BigDecimal money = rs.getBigDecimal("money");//��ȡ��ѯ����е�money
                String date = rs.getString("date");//��ȡ��ѯ����е�date
                HomeCost homeCost = new HomeCost(id, name, money, date);//���ù��췽����ֵ
                list.add(homeCost);//��ӵ�list������
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            DBUtils.close(rs, state, conn);
        }
        return list;
    }

    public HomeCost getHomeCostById(int id) {
        String sql = "select * from record where id ='" + id + "'";
        Connection conn = DBUtils.getConn();
        Statement state = null;
        ResultSet rs = null;
        HomeCost homeCost = null;
        try {
            state = conn.createStatement();
            rs = state.executeQuery(sql);
            while (rs.next()) {
                String name = rs.getString("name");
                BigDecimal money = rs.getBigDecimal("money");
                String date = rs.getString("date");
                String remarks = rs.getString("remarks");
                homeCost = new HomeCost(id, name, money, date, remarks);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            DBUtils.close(rs, state, conn);
        }
        return homeCost;
    }

    public BigDecimal queryMoneySum(int id) {
        String sql = "select money from record where id <=" + id;
        BigDecimal sum = new BigDecimal("0.00");
        Connection conn = DBUtils.getConn();
        Statement state = null;
        ResultSet rs = null;
        try {
            state = conn.createStatement();
            rs = state.executeQuery(sql);
            while (rs.next()) {
                BigDecimal money = rs.getBigDecimal("money");
                //sum��money�ۼ�ֵ
                sum = sum.add(money);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            DBUtils.close(rs, state, conn);
        }
        return sum;
    }

    public List<HomeCost> list(int uid) {
        //String user = "" + uid;
        String sql = "select * from record where user_id=" + uid;
        List<HomeCost> list = new ArrayList<>();
        Connection conn = DBUtils.getConn();
        Statement state = null;
        ResultSet rs = null;
        try {
            state = conn.createStatement();
            rs = state.executeQuery(sql);
            HomeCost homeCost = null;
            while (rs.next()) {
                int id = rs.getInt("id");
                BigDecimal sum = queryMoneySum(id);
                String name = rs.getString("name");
                BigDecimal money = rs.getBigDecimal("money");
                String date = rs.getString("date");
                String remarks = rs.getString("remarks");
                homeCost = new HomeCost(id, name, money, date, sum, remarks);
                list.add(homeCost);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            DBUtils.close(rs, state, conn);
        }
        return list;
    }


}
