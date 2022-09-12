package com.example.trabalho1;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;


public class Tab_RecycleView extends Fragment {

    androidx.recyclerview.widget.RecyclerView recyclerView;

    String langs_titles[], langs_descs[];
    int images[] = {R.drawable.programinglang_cplspls, R.drawable.programinglang_java, R.drawable.programinglang_js,
            R.drawable.programinglang_python, R.drawable.programinglang_react, R.drawable.programinglang_ts, R.drawable.programinglang_ruby,
            R.drawable.programinglang_vsbasic, R.drawable.programinglang_csharp};

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public Tab_RecycleView() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment Fragment_RecycleView.
     */
    // TODO: Rename and change types and number of parameters
    public static Tab_RecycleView newInstance(String param1, String param2) {
        Tab_RecycleView fragment = new Tab_RecycleView();
        Bundle args = new Bundle();
        args.putString(ARG_PARAM1, param1);
        args.putString(ARG_PARAM2, param2);
        fragment.setArguments(args);
        return fragment;
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

        View v = inflater.inflate(R.layout.tab_recycler_view, container, false);

        langs_titles = getResources().getStringArray(R.array.programing_langs);
        langs_descs = getResources().getStringArray(R.array.langs_description);

        recyclerView = v.findViewById(R.id.recyclerView);

        Adapter_RecyclerView myAdapter = new Adapter_RecyclerView(getActivity(), langs_titles, langs_descs, images);
        recyclerView.setAdapter(myAdapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(getActivity()));

        // Inflate the layout for this fragment
        return v;
    }
}