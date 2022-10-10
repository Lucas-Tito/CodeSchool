package com.example.assignment2.model;

import java.io.Serializable;

public class Car implements Serializable {

    private int id;
    private String description, category;

    Car(int id, String description, String category){
        this.id = id;
        this.description = description;
        this.category = category;
    }

    public int getId() {
        return id;
    }


    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }
}
