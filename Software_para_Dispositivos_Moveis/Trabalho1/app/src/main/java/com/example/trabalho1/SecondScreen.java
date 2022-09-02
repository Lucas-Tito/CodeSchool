package com.example.trabalho1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class SecondScreen extends AppCompatActivity {

    MediaPlayer oldie_song;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second_screen);

        build_play_btn();

    }

    @Override
    protected void onPause() {
        super.onPause();
        oldie_song.release();
    }

    @Override
    public void finish(){

        super.finish();
        //muda a animação de saída da tela
        overridePendingTransition(R.anim.slide_in_left, R.anim.slide_out_right);

    }


    private void build_play_btn() {

        Button playBtn = findViewById(R.id.play_btn);
        oldie_song = MediaPlayer.create(this, R.raw.oldie_song);
        playBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                oldie_song.start();

            }
        });


    }
}