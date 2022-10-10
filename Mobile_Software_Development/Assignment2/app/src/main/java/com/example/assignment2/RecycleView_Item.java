package com.example.assignment2;

public class RecycleView_Item {

    private String description;
    private String category;


    RecycleView_Item(String description, String category){

        this.description = description;
        this.category = category;

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
