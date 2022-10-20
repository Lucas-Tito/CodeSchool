package com.example.assignment2;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.example.assignment2.Adapters.Adapter_RecyclerView;
import com.example.assignment2.DAO.CarDAO;
import com.example.assignment2.model.Car;

public class MainActivity extends AppCompatActivity {

    CarDAO carDAO = new CarDAO();
    Adapter_RecyclerView myAdapter;




    //Override method to receive updated expenses from other activities
    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);


        if (requestCode == 101)
            if(resultCode == MainActivity.RESULT_OK)
                carDAO.addCar( (Car) data.getSerializableExtra("newCar"));


        if (requestCode == 102)
            if(resultCode == MainActivity.RESULT_OK)
                carDAO = (CarDAO) data.getSerializableExtra("newCarDao");



    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //adding car just for testing
        carDAO.addCar(new Car(0, "mercedes", "4x4"));

        build_recyclerView();
        build_add_btn();
        build_edit_btn();
    }

    @Override
    protected void onResume() {
        super.onResume();

        //refresh recyclerView to show new items
        myAdapter.notifyDataSetChanged();
    }

    private void build_recyclerView() {

        androidx.recyclerview.widget.RecyclerView recyclerView;
        recyclerView = findViewById(R.id.recyclerView);

        myAdapter = new Adapter_RecyclerView(this, carDAO);
        recyclerView.setAdapter(myAdapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));

    }


    public void build_add_btn(){

        Button add_btn = findViewById(R.id.add_btn);

        add_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this, MainActivity2.class);
                intent.putExtra("fragToStart", 1);
                intent.putExtra("carID", carDAO.getSize());
                startActivityForResult(intent, 101);
            }
        });

    }

    public void build_edit_btn(){

        Button edit_btn = findViewById(R.id.edit_btn);
        EditText id_label = findViewById(R.id.id_label);

        edit_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if(TextUtils.isEmpty(id_label.getText().toString())){
                    Toast.makeText(MainActivity.this, "id field is empty", Toast.LENGTH_LONG).show();
                }
                else if(Integer.parseInt(id_label.getText().toString()) < 0
                        || Integer.parseInt(id_label.getText().toString()) >= carDAO.getSize() ){
                    Toast.makeText(MainActivity.this, "id provided is out of bounds", Toast.LENGTH_LONG).show();
                }
                else {
                    Intent intent = new Intent(MainActivity.this, MainActivity2.class);
                    intent.putExtra("fragToStart", 2);
                    int carID = Integer.parseInt(id_label.getText().toString());
                    intent.putExtra("carID", carID);
                    intent.putExtra("carDao", carDAO);
                    startActivityForResult(intent, 102);
                }
            }
        });

    }
}