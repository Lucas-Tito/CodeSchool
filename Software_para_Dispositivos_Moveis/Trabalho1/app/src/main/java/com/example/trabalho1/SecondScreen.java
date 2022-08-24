package com.example.trabalho1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

public class SecondScreen extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second_screen);

    }

    @Override
    public void finish(){

        super.finish();
        overridePendingTransition(R.anim.slide_in_left, R.anim.slide_out_right);    //muda a animação de saída da tela

    }
}