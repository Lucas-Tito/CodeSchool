package com.example.trabalho1;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;

import android.os.Bundle;

public class RecyclerView extends AppCompatActivity {

    androidx.recyclerview.widget.RecyclerView recyclerView;

    String langs_titles[], langs_descs[];
    int images[] = {R.drawable.programinglang_cplspls, R.drawable.programinglang_java, R.drawable.programinglang_js,
    R.drawable.programinglang_python, R.drawable.programinglang_react, R.drawable.programinglang_ts, R.drawable.programinglang_ruby,
    R.drawable.programinglang_vsbasic, R.drawable.programinglang_csharp};


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_recycler_view);

        langs_titles = getResources().getStringArray(R.array.programing_langs);
        langs_descs = getResources().getStringArray(R.array.langs_description);

        recyclerView = findViewById(R.id.recyclerView);

        recyclerViewAdapter myAdapter = new recyclerViewAdapter(this, langs_titles, langs_descs, images);
        recyclerView.setAdapter(myAdapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
    }
}