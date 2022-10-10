package com.example.trabalho1;

import android.os.Bundle;
import android.view.MenuItem;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;

import com.google.android.material.bottomnavigation.BottomNavigationView;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        build_bottom_nav();

    }



    public void build_bottom_nav(){

        BottomNavigationView bottom_nav_view;

        bottom_nav_view = findViewById(R.id.bottomNavigationView);
        getSupportFragmentManager().beginTransaction().replace(R.id.frame_layout, new Tab_Layout()).commit();
        bottom_nav_view.setSelectedItemId(R.id.home);

        bottom_nav_view.setOnNavigationItemSelectedListener(new BottomNavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(@NonNull MenuItem item) {
                Fragment fragment = null;

                switch (item.getItemId()){

                    case R.id.home:
                        fragment = new Tab_Layout();
                        break;

                    case R.id.grid:
                        fragment = new Grid_View();
                        break;

                }
                getSupportFragmentManager().beginTransaction().replace(R.id.frame_layout, fragment).commit();
                return true;
            }
        });

    }



}