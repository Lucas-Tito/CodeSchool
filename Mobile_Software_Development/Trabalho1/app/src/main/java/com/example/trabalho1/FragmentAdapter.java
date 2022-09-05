package com.example.trabalho1;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentActivity;
import androidx.viewpager2.adapter.FragmentStateAdapter;

public class FragmentAdapter extends FragmentStateAdapter {

    //This class is used to implement tabLayout from main_activity
    public FragmentAdapter(@NonNull FragmentActivity fragmentActivity) {
        super(fragmentActivity);
    }

    @NonNull
    @Override
    public Fragment createFragment(int position) {
        switch (position){
            case 0:
                return new Fragment_Misc_Elements1();

            case 1:
                return new Fragment_Misc_Elements2();

            case 2:
                return new Fragment_RecycleView();

            default:
                return new Fragment_Misc_Elements1();
        }
    }

    @Override
    public int getItemCount() {
        return 3;
    }
}
