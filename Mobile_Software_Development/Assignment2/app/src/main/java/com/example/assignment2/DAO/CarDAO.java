package com.example.assignment2.DAO;

import com.example.assignment2.model.Car;

import java.io.Serializable;
import java.util.ArrayList;

public class CarDAO implements Serializable {

    ArrayList<Car> cars = new ArrayList<>();


    public void addCar(Car car){
        cars.add(car);
    }

    public void removeCar(int id){
        cars.remove(id);
    }

    public void editCar(int id, String description, String category){
        cars.get(id).setDescription(description);
        cars.get(id).setCategory(category);
    }

    public Car get(int pos){
        return cars.get(pos);
    }

    public ArrayList getAll(){
        return cars;
    }

    public int getSize(){
        return cars.size();
    }

}
