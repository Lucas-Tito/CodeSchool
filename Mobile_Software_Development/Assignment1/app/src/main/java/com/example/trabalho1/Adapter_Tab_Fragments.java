package com.example.trabalho1;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentActivity;
import androidx.viewpager2.adapter.FragmentStateAdapter;

public class Adapter_Tab_Fragments extends FragmentStateAdapter {

    //This class is used to implement tabLayout from main_activity
    public Adapter_Tab_Fragments(@NonNull FragmentActivity fragmentActivity) {
        super(fragmentActivity);
    }

    @NonNull
    @Override
    public Fragment createFragment(int position) {
        switch (position){
            case 0:
                return new Tab_Misc_Elements1();

            case 1:
                return new Tab_Misc_Elements2();

            case 2:
                return new Tab_RecycleView();

            default:
                return new Tab_Misc_Elements1();
        }
    }

    @Override
    public int getItemCount() {
        return 3;
    }
}
