package com.example.assignment2;

import android.content.Intent;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.os.CancellationSignal;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.ImageButton;

import com.example.assignment2.DAO.CarDAO;


public class activity2_edit_car extends Fragment {

    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String carDAO_key = "carDAO_key";
    private static final String carID_key = "carID_key";

    private CarDAO carDAO;
    private int carID;


    EditText description;
    EditText category;

    public activity2_edit_car() {
        // Required empty public constructor
    }


    public static activity2_edit_car newInstance(CarDAO carDAO, int carID) {
        activity2_edit_car fragment = new activity2_edit_car();
        Bundle args = new Bundle();
        args.putSerializable(carDAO_key, carDAO);
        args.putInt(carID_key, carID);
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (getArguments() != null) {
            carDAO = (CarDAO) getArguments().getSerializable(carDAO_key);
            carID = getArguments().getInt(carID_key);
        }
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View v = inflater.inflate(R.layout.fragment_activity2_edit_car, container, false);

        description = v.findViewById(R.id.description);
        category = v.findViewById(R.id.category);

        buildView(carID);
        build_confirm_btn(v);

        return v;
    }


    private void buildView(int carID){

        description.setText(carDAO.get(carID).getDescription());
        category.setText(carDAO.get(carID).getCategory());

    }

    private void build_confirm_btn(View v){

        ImageButton confirm_btn = v.findViewById(R.id.confirm_btn);

        confirm_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                carDAO.get(carID).setDescription(description.getText().toString());
                carDAO.get(carID).setCategory(category.getText().toString());

                Intent returnIntent = new Intent();
                returnIntent.putExtra("newCarDao", carDAO);
                getActivity().setResult(getActivity().RESULT_OK, returnIntent);
                getActivity().finish();
            }
        });

    }


}