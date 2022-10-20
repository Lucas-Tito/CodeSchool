package com.example.assignment2;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;

import android.os.Bundle;
import android.view.View;
import android.widget.ImageButton;
import android.widget.TextView;

import com.example.assignment2.DAO.CarDAO;

public class MainActivity2 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        build_back_btn();
        build_frame_layout();
    }



    private void build_back_btn() {

        ImageButton back_btn = findViewById(R.id.back_btn);

        back_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();
            }
        });

    }


    private void build_frame_layout(){

        Fragment fragmentToStart = null;

        CarDAO carDAO = (CarDAO) getIntent().getSerializableExtra("carDao");



        if(getIntent().getIntExtra("fragToStart", 0) == 1){
            int carID = getIntent().getIntExtra("carID", 0);
            fragmentToStart = activity2_add_car.newInstance(carID);
        }
        else if(getIntent().getIntExtra("fragToStart", 0) == 2){
            int carID = getIntent().getIntExtra("carID", 0);
            fragmentToStart = activity2_edit_car.newInstance(carDAO, carID );
        }

        getSupportFragmentManager().beginTransaction().replace(R.id.frame_layout, fragmentToStart).commit();

    }
}


