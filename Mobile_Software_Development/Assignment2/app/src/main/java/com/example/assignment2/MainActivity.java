package com.example.assignment2;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.example.assignment2.Adapters.Adapter_RecyclerView;
import com.example.assignment2.Adapters.Interface_RecyclerView;
import com.example.assignment2.DAO.CarDAO;
import com.example.assignment2.model.Car;

public class MainActivity extends AppCompatActivity implements Interface_RecyclerView {

    CarDAO carDAO = new CarDAO();




    //Override method to receive updated expenses from other activities
    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == 101)
            if(resultCode == MainActivity.RESULT_OK){
                carDAO = (CarDAO) data.getSerializableExtra("newCarDao");

            }


    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //adding car just for testing
        carDAO.addCar(new Car(1, "mercedes", "4x4"));

        build_recyclerView();
        build_add_btn();
        build_edit_btn();
    }

    @Override
    protected void onResume() {
        super.onResume();

        //refresh recyclerView to show new items
        build_recyclerView();
    }

    private void build_recyclerView() {

        androidx.recyclerview.widget.RecyclerView recyclerView;
        recyclerView = findViewById(R.id.recyclerView);

        Adapter_RecyclerView myAdapter = new Adapter_RecyclerView(this, carDAO, this);
        recyclerView.setAdapter(myAdapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));

    }

    //click listener for recycleView items
    @Override
    public void onItemClick(int position, String fragToStart) {

/*        Intent intent = new Intent(getActivity(), Edit_Transaction_Activity.class);
        intent.putExtra("transaction_pos", position);
        intent.putExtra("expenseDao", this.expenseDAO);
        intent.putExtra("incomeDao", this.incomeDAO);

        if(fragToStart.equals("editExpense")){
            intent.putExtra("frag_key", fragToStart);
            getActivity().startActivityForResult(intent, 101);
        }
        else{
            intent.putExtra("frag_key", fragToStart);
            getActivity().startActivityForResult(intent, 102);
        }*/

    }


    public void build_add_btn(){

        Button add_btn = findViewById(R.id.add_btn);

        add_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this, MainActivity2.class);
                intent.putExtra("fragToStart", 1);
                intent.putExtra("carDao", carDAO);
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
                Intent intent = new Intent(MainActivity.this, MainActivity2.class);
                intent.putExtra("fragToStart", 2);
                int carID = Integer.parseInt(id_label.getText().toString());
                intent.putExtra("carID", carID);
                intent.putExtra("carDao", carDAO);
                startActivityForResult(intent, 101);
            }
        });

    }
}