package com.example.assignment2;

import android.content.Intent;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.Switch;
import android.widget.TextView;

import com.example.assignment2.DAO.CarDAO;
import com.example.assignment2.model.Car;

import java.util.Date;


public class activity2_add_car extends Fragment {

    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String carDAO_key = "carDAO_key";

    private CarDAO carDAO;

    public activity2_add_car() {
        // Required empty public constructor
    }


    public static activity2_add_car newInstance(CarDAO carDAO) {
        activity2_add_car fragment = new activity2_add_car();
        Bundle args = new Bundle();
        args.putSerializable(carDAO_key, carDAO);
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (getArguments() != null) {
            carDAO = (CarDAO) getArguments().getSerializable(carDAO_key);
        }
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View v = inflater.inflate(R.layout.fragment_activity2_add_car, container, false);

        build_confirm_btn(v);

        return v;
    }


    public void build_confirm_btn(View v){

        ImageButton confirm_btn = v.findViewById(R.id.confirm_btn);
        EditText description_label = v.findViewById(R.id.description);
        EditText category_label = v.findViewById(R.id.category);

        confirm_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                String description = description_label.getText().toString();
                String category = category_label.getText().toString();

                Car newCar = new Car(carDAO.getSize(), description, category);
                carDAO.addCar(newCar);

                Intent returnIntent = new Intent();
                returnIntent.putExtra("newCarDao", carDAO);
                getActivity().setResult(getActivity().RESULT_OK, returnIntent);
                getActivity().finish();
            }
        });

    }
}