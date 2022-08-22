package com.example.trabalho1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.Toast;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener {

    String[] dropdown_menu = {"somos", "elementos", "do array"};


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Spinner spiner = findViewById(R.id.dropdown_menu);
        spiner.setOnItemSelectedListener(this);

        //converte o array em elementos do dropdown
        ArrayAdapter aa = new ArrayAdapter(this, android.R.layout.simple_spinner_item, dropdown_menu);
        aa.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spiner.setAdapter(aa);
        //-----------------------------------------
    }

    @Override
    public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
        Toast.makeText(this, dropdown_menu[i], Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onNothingSelected(AdapterView<?> adapterView) {

    }
}