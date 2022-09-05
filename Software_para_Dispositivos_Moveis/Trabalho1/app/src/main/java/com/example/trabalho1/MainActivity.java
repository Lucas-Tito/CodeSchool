package com.example.trabalho1;

import androidx.annotation.NonNull;
import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentPagerAdapter;
import androidx.viewpager.widget.ViewPager;
import androidx.viewpager2.adapter.FragmentStateAdapter;
import androidx.viewpager2.widget.ViewPager2;

import android.content.pm.PackageManager;
import android.content.Context;
import android.content.Intent;
import android.hardware.Camera;
import android.hardware.camera2.CameraAccessException;
import android.hardware.camera2.CameraManager;
import android.os.Build;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.Spinner;
import android.widget.TableLayout;
import android.widget.Toast;
import android.widget.ToggleButton;

import com.google.android.material.tabs.TabLayout;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Toolbar toolbar = findViewById(R.id.toolbar);
        toolbar.setTitle("");
        setSupportActionBar(toolbar);

        build_tab_layout();

        /*
        build_spinner();
        build_autocomplete_countries();
        build_btn_nextScreen();
        build_toggle_button();
        */
    }

    //---------------------------TOOLBAR------------------------------------------------------------+
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {

    getMenuInflater().inflate(R.menu.main_menu, menu);
    return super.onCreateOptionsMenu(menu);

    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {

        if(item.getItemId() == R.id.settings_btn){
            Toast.makeText(MainActivity.this, "you clicked in settings", Toast.LENGTH_LONG).show();
        }

        return super.onOptionsItemSelected(item);

    }
    //----------------------------------------------------------------------------------------------+



    private void build_tab_layout(){
        TabLayout tabLayout = findViewById(R.id.tabLayout);
        ViewPager2 viewPager = findViewById(R.id.viewPager);

        FragmentAdapter fgAdapter = new FragmentAdapter(this);

        viewPager.setAdapter(fgAdapter);

        tabLayout.addOnTabSelectedListener(new TabLayout.OnTabSelectedListener() {
            @Override
            public void onTabSelected(TabLayout.Tab tab) {
                viewPager.setCurrentItem(tab.getPosition());
            }

            @Override
            public void onTabUnselected(TabLayout.Tab tab) {

            }

            @Override
            public void onTabReselected(TabLayout.Tab tab) {

            }
        });

    }

    /*
    private void build_toggle_button(){

        ToggleButton tgl_btn = findViewById(R.id.toggleButton);
        CameraManager cameraManager = (CameraManager) getSystemService(Context.CAMERA_SERVICE);

        tgl_btn.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean isChecked) {
                String getCameraId;

                if(!isChecked){
                    try {
                        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                            String cameraId = cameraManager.getCameraIdList()[0];
                            cameraManager.setTorchMode(cameraId,false);
                        }
                    } catch (CameraAccessException e) {
                        e.printStackTrace();
                    }
                }
                else{
                    if(getPackageManager().hasSystemFeature(PackageManager.FEATURE_CAMERA_FLASH))
                    {
                        //dipositivo tem flash
                        try {

                            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                                getCameraId = cameraManager.getCameraIdList()[0];
                                cameraManager.setTorchMode(getCameraId,true  );
                            }
                        } catch (CameraAccessException e) {
                            e.printStackTrace();
                        }
                    }else
                    {
                        Toast.makeText(MainActivity.this, "Esse dispositivo não possui flash", Toast.LENGTH_SHORT).show();
                        compoundButton.setChecked(false);
                    }
                }
            }
        });
    }



    private void build_spinner(){

        String[] dropdown_menu = {"somos", "elementos", "do array"};
        Spinner spinner = findViewById(R.id.dropdown_menu);

        //converte o array em elementos do dropdown
        ArrayAdapter aa = new ArrayAdapter(this, android.R.layout.simple_spinner_item, dropdown_menu);
        aa.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinner.setAdapter(aa);
        //-----------------------------------------

    }



    private void build_autocomplete_countries() {

        String[] countries = {"Afghanistan","Albania","Algeria","Andorra","Angola","Anguilla","Antigua &amp; Barbuda","Argentina","Armenia","Aruba","Australia","Austria","Azerbaijan","Bahamas","Bahrain","Bangladesh","Barbados","Belarus","Belgium","Belize","Benin","Bermuda","Bhutan","Bolivia","Bosnia &amp; Herzegovina","Botswana","Brazil","British Virgin Islands","Brunei","Bulgaria","Burkina Faso","Burundi","Cambodia","Cameroon","Cape Verde","Cayman Islands","Chad","Chile","China","Colombia","Congo","Cook Islands","Costa Rica","Cote D Ivoire","Croatia","Cruise Ship","Cuba","Cyprus","Czech Republic","Denmark","Djibouti","Dominica","Dominican Republic","Ecuador","Egypt","El Salvador","Equatorial Guinea","Estonia","Ethiopia","Falkland Islands","Faroe Islands","Fiji","Finland","France","French Polynesia","French West Indies","Gabon","Gambia","Georgia","Germany","Ghana","Gibraltar","Greece","Greenland","Grenada","Guam","Guatemala","Guernsey","Guinea","Guinea Bissau","Guyana","Haiti","Honduras","Hong Kong","Hungary","Iceland","India","Indonesia","Iran","Iraq","Ireland","Isle of Man","Israel","Italy","Jamaica","Japan","Jersey","Jordan","Kazakhstan","Kenya","Kuwait","Kyrgyz Republic","Laos","Latvia","Lebanon","Lesotho","Liberia","Libya","Liechtenstein","Lithuania","Luxembourg","Macau","Macedonia","Madagascar","Malawi","Malaysia","Maldives","Mali","Malta","Mauritania","Mauritius","Mexico","Moldova","Monaco","Mongolia","Montenegro","Montserrat","Morocco","Mozambique","Namibia","Nepal","Netherlands","Netherlands Antilles","New Caledonia","New Zealand","Nicaragua","Niger","Nigeria","Norway","Oman","Pakistan","Palestine","Panama","Papua New Guinea","Paraguay","Peru","Philippines","Poland","Portugal","Puerto Rico","Qatar","Reunion","Romania","Russia","Rwanda","Saint Pierre &amp; Miquelon","Samoa","San Marino","Satellite","Saudi Arabia","Senegal","Serbia","Seychelles","Sierra Leone","Singapore","Slovakia","Slovenia","South Africa","South Korea","Spain","Sri Lanka","St Kitts &amp; Nevis","St Lucia","St Vincent","St. Lucia","Sudan","Suriname","Swaziland","Sweden","Switzerland","Syria","Taiwan","Tajikistan","Tanzania","Thailand","Timor L'Este","Togo","Tonga","Trinidad &amp; Tobago","Tunisia","Turkey","Turkmenistan","Turks &amp; Caicos","Uganda","Ukraine","United Arab Emirates","United Kingdom","Uruguay","Uzbekistan","Venezuela","Vietnam","Virgin Islands (US)","Yemen","Zambia","Zimbabwe"};

        AutoCompleteTextView autocomplete = findViewById(R.id.autoCompleteTextView);

        //converte o array em elementos do autocomplete
        ArrayAdapter Caa = new ArrayAdapter(this, android.R.layout.simple_list_item_1, countries);
        autocomplete.setAdapter(Caa);
        //-----------------------------------------

    }


    private void build_btn_nextScreen() {

        Button btnNextScreen = findViewById(R.id.nextScreenBtn);

        btnNextScreen.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Intent secondaryScreen = new Intent(getApplicationContext(), SecondScreen.class);
                startActivity(secondaryScreen);
                //muda a animação de transição para second_screen
                overridePendingTransition(R.anim.slide_in_right, R.anim.slide_out_left);

            }
        });

        btnNextScreen.setOnLongClickListener(new View.OnLongClickListener() {

        @Override
        public boolean onLongClick(View v){

            Toast.makeText(MainActivity.this, "you clicked me for a long time", Toast.LENGTH_LONG).show();
            return false;

        }

        });
    }
*/

}