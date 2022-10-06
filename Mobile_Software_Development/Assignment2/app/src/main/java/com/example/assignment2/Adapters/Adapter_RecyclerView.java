package com.example.assignment2.Adapters;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;


import com.example.assignment2.Item;
import com.example.assignment2.R;

import java.util.ArrayList;

public class Adapter_RecyclerView extends RecyclerView.Adapter<Adapter_RecyclerView.MyViewHolder> {

    ArrayList<Item> items = new ArrayList<>();
    Context context;
    private final Interface_RecyclerView recyclerViewInterface;

    public Adapter_RecyclerView(Context ct, ArrayList<Item> items, Interface_RecyclerView recyclerViewInterface){
        this.items = items;
        context = ct;
        this.recyclerViewInterface = recyclerViewInterface;
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

        holder.description_label.setText(items.get(position).getDescription());
        holder.category_label.setText(items.get(position).getCategory());

    }

    @Override
    public int getItemCount() {
        return items.size();
    }

    public class MyViewHolder extends RecyclerView.ViewHolder{
        TextView date_label, description_label,
                category_label, amount_label;

        public MyViewHolder(@NonNull View itemView){
            super(itemView);

            description_label = itemView.findViewById(R.id.description_label);
            category_label = itemView.findViewById(R.id.category_label);


/*            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    if(recyclerViewInterface!=null){
                        int pos = getAdapterPosition();
                        Transaction transaction = items.get(pos);
                        pos = transaction.getId();
                        String fragToStart;

                        if(transaction instanceof Expense)
                            fragToStart = "editExpense";
                        else
                            fragToStart = "editIncome";

                        recyclerViewInterface.onItemClick(pos, fragToStart);
                    }
                }
            });*/
        }
    }

}
