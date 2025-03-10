package com.al_1suyan.dao.impl;

import com.al_1suyan.common.HibernateUtil;
import com.al_1suyan.dao.StudentDao;
import com.al_1suyan.domain.Student;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;

import java.util.List;


public class StudentDaoImpl implements StudentDao {
    private static SessionFactory sessionFactory= HibernateUtil.getSessionFactory();
    @Override
    public Student findByUsername(String username){
        Session session=sessionFactory.openSession();
        String hql="from Student where username='"+username+"'";
        Student student =(Student)session.createQuery(hql).uniqueResult();
        session.close();
        return student;
    }
    @Override
    public List<Student> list(String username){
        Session session=sessionFactory.openSession();
        String hql="from Student where username like ?";
        List<Student> list=session.createQuery(hql).setString(0,"%"+username+"%").list();
        session.close();
        return list;
    }
    @Override
    public boolean add(Student student){
        Session session=null;
        Transaction transaction=null;
        try{
            session=sessionFactory.openSession();
            transaction=session.beginTransaction();
            session.save(student);
            transaction.commit();
            return true;
        }catch(Exception e){
            if(transaction!=null){
                transaction.rollback();
            }
            e.printStackTrace();
        }finally{
            if(session!=null){
                session.close();
            }
        }
        return false;
    }
    @Override
    public Student findById(int id){
        Session session=sessionFactory.openSession();
        String hql="from Student where id=?";
        Student student =(Student)session.createQuery(hql).setInteger(0,id).uniqueResult();
        session.close();
        return student;

    }
    @Override
    public boolean update(Student student){
        Session session=null;
        Transaction transaction=null;
        try{
            session=sessionFactory.openSession();
            transaction=session.beginTransaction();
            session.update(student);
            transaction.commit();
            return true;
        }catch(Exception e){
            if(transaction!=null){
                transaction.rollback();
            }
            e.printStackTrace();
        }finally{
            if(session!=null){
                session.close();
            }
        }
        return false;
    }
    public boolean delete(Student student){
        Session session=null;
        Transaction transaction=null;
        try{
            session=sessionFactory.openSession();
            transaction=session.beginTransaction();
            session.delete(student);
            transaction.commit();
            return true;
        }catch(Exception e){
            if(transaction!=null){
                transaction.rollback();
            }
            e.printStackTrace();
        }finally{
            if(session!=null){
                session.close();
            }
        }
        return false;
    }
}

