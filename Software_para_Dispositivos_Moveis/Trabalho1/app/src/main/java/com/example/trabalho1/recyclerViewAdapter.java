package com.example.trabalho1;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

public class recyclerViewAdapter extends RecyclerView.Adapter<recyclerViewAdapter.MyViewHolder> {

    String data1[], data2[];
    int images[];
    Context context;

    public recyclerViewAdapter(Context ct, String lang_titles[], String lang_desc[], int images[]){
        context = ct;
        data1 = lang_titles;
        data2 = lang_desc;
        this.images = images;
    }

    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        LayoutInflater inflater = LayoutInflater.from(context);
        View view = inflater.inflate(R.layout.my_row, parent, false);

        return new MyViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder holder, int position) {
        holder.lang_title.setText(data1[position]);
        holder.lang_desc.setText(data2[position]);
        holder.lang_logo.setImageResource(images[position]);
    }

    @Override
    public int getItemCount() {
        return data1.length;
    }

    public class MyViewHolder extends RecyclerView.ViewHolder{
        TextView lang_title, lang_desc;
        ImageView lang_logo;
        public MyViewHolder(@NonNull View itemView){
            super(itemView);
            lang_title = itemView.findViewById(R.id.lang_title);
            lang_desc = itemView.findViewById(R.id.lang_desc);
            lang_logo = itemView.findViewById(R.id.lang_img);
        }
    }

}
