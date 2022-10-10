package com.example.assignment2;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;

import android.os.Bundle;

import com.example.assignment2.Adapters.Adapter_RecyclerView;
import com.example.assignment2.Adapters.Interface_RecyclerView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity implements Interface_RecyclerView {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        build_recyclerView();
    }



    private void build_recyclerView() {

        ArrayList<RecycleView_Item> items = new ArrayList<>();
        items.add(new RecycleView_Item("mercedes", "carro"));

        androidx.recyclerview.widget.RecyclerView recyclerView;
        recyclerView = findViewById(R.id.recyclerView);

        Adapter_RecyclerView myAdapter = new Adapter_RecyclerView(this, items, this);
        recyclerView.setAdapter(myAdapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));

    }

    //click listener for recycleView items
    @Override
    public void onItemClick(int position, String fragToStart) {

/*        Intent intent = new Intent(getActivity(), Edit_Transaction_Activity.class);
        intent.putExtra("transaction_pos", position);
        intent.putExtra("expenseDao", this.expenseDAO);
        intent.putExtra("incomeDao", this.incomeDAO);

        if(fragToStart.equals("editExpense")){
            intent.putExtra("frag_key", fragToStart);
            getActivity().startActivityForResult(intent, 101);
        }
        else{
            intent.putExtra("frag_key", fragToStart);
            getActivity().startActivityForResult(intent, 102);
        }*/

    }
}