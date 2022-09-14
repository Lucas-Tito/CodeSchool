package com.example.trabalho1;

import android.content.Context;
import android.content.pm.PackageManager;
import android.hardware.camera2.CameraAccessException;
import android.hardware.camera2.CameraManager;
import android.media.MediaPlayer;
import android.os.Build;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.Toast;
import android.widget.ToggleButton;


public class Tab_Misc_Elements2 extends Fragment {
    //initialize song
    MediaPlayer oldie_song;
    boolean playBtn_wasClicked = false;
    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public Tab_Misc_Elements2() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment Misc_Elements2.
     */
    // TODO: Rename and change types and number of parameters
    public static Tab_Misc_Elements2 newInstance(String param1, String param2) {
        Tab_Misc_Elements2 fragment = new Tab_Misc_Elements2();
        Bundle args = new Bundle();
        args.putString(ARG_PARAM1, param1);
        args.putString(ARG_PARAM2, param2);
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onPause() {
        super.onPause();
        /**pause song when fragment is away
         * if is used to prevent weird bug when trying to start music again
         */
        if(playBtn_wasClicked)
            oldie_song.pause();
    }

    @Override
    public void onResume() {
        super.onResume();
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (getArguments() != null) {
            mParam1 = getArguments().getString(ARG_PARAM1);
            mParam2 = getArguments().getString(ARG_PARAM2);
        }
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View v = inflater.inflate(R.layout.tab_misc_elements2, container, false);

        build_play_btn(v);
        build_toggle_button(v);

        return v;
    }


    private void build_play_btn(View v) {

        Button playBtn = v.findViewById(R.id.play_btn);
        oldie_song = MediaPlayer.create(getActivity(), R.raw.oldie_song);
        playBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                oldie_song.start();
                playBtn_wasClicked = true;
            }
        });

    }



    private void build_toggle_button(View v){

        ToggleButton tgl_btn = v.findViewById(R.id.toggleButton);
        CameraManager cameraManager = (CameraManager) getActivity().getSystemService(Context.CAMERA_SERVICE);

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
                    if(getActivity().getPackageManager().hasSystemFeature(PackageManager.FEATURE_CAMERA_FLASH))
                    {
                        //device has torch
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
                        Toast.makeText(getContext(), "this device has no torch", Toast.LENGTH_SHORT).show();
                        compoundButton.setChecked(false);
                    }
                }
            }
        });

        tgl_btn.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View view) {
                Toast.makeText(getActivity(), "you clicked me for a long time", Toast.LENGTH_SHORT).show();
                return false;
            }
        });
    }


}