package com.example.assignment2.Adapters;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;


import com.example.assignment2.DAO.CarDAO;
import com.example.assignment2.R;

public class Adapter_RecyclerView extends RecyclerView.Adapter<Adapter_RecyclerView.MyViewHolder> {

    CarDAO carDAO = new CarDAO();
    Context context;

    public Adapter_RecyclerView(Context ct, CarDAO carDAO){
        this.carDAO = carDAO;
        context = ct;

    }

    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        LayoutInflater inflater = LayoutInflater.from(context);
        View view = inflater.inflate(R.layout.list_items, parent, false);

        return new MyViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder holder, int position) {

        holder.description_label.setText(carDAO.get(position).getDescription());
        holder.category_label.setText(carDAO.get(position).getCategory());
        holder.id_label.setText(Integer.toString(carDAO.get(position).getId()));

    }

    @Override
    public int getItemCount() {
        return carDAO.getSize();
    }

    public class MyViewHolder extends RecyclerView.ViewHolder{
        TextView description_label,
                category_label, id_label;

        public MyViewHolder(@NonNull View itemView){
            super(itemView);

            description_label = itemView.findViewById(R.id.description_label);
            category_label = itemView.findViewById(R.id.category_label);
            id_label = itemView.findViewById(R.id.id_TextView);

        }
    }

}
