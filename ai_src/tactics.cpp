#include "tactics.hpp"

Tactics::Tactics(){
    set_default();
}

void Tactics::set_default(){
    tegawari_num[0] = 2;
    tegawari_num[1] = 2;
    tegawari_num[2] = 1;
    tegawari_num[3] = 1;
    tegawari_num[4] = 0;
    tegawari_num[5] = 0;
    tegawari_num[6] = 0;
    do_houjuu_discount = false;
    do_speed_modify = false;
    use_larger_at_cal_tenpai_after = false;
    betaori_compare_at_2fuuro = false;
    do_kan = true;
    do_kyushukyuhai = false;
    use_nn_keiten_estimator = false;
    use_nn_kyoku_result_target_estimator = false;
    use_nn_kyoku_result_other_agari_estimator = false;
    use_ori_choice_exception = false;
    use_new_agari_ml = false;
    use_agari_coeff_old = false;
    use_agari_coeff_tp = false;
    use_agari_coeff_fp = false;
    modify_always = false;
    use_rule_base_at_mentu5_titoi3_shanten = true;
    use_cn_max_addition_if_honitsu = false;
    use_reach_daten_data_flag = false;
    do_tsumo_prob_dora_shift = false;
    use_no_fuuro_data_flag = false;
    use_new_other_end_prob = true;
    use_fuuro_choice_simple = false;
    use_tenpai_prob_other_zero_fuuro_exception = false;
    use_ori_choice_exception_near_lose = false;
    use_reach_tenpai_prob_other_if_other_reach = true;
    use_han_shift_at_fuuro_estimation = false;
    use_han_shift_at_fuuro_estimation2 = false;
    use_new_tenpai_est_tmp = false;
    use_ratio_tas_to_coeff = true;
    use_ori_exp_at_dp_fuuro = true;
    jun_calc_bug = false;
    use_yama_ratio_kawa_num = 100;
    use_dp_last_tsumo_num = 0;
    jun_est_type = JET_DEFAULT;
    inclusive_sn_always = 1;
    inclusive_sn_other_reach = 2;
    inclusive_sn_fp = 1;
    inclusive_sn_fp_other_reach = 2;
    reach_regression_mode_default = 1;
    reach_regression_mode_other_reach = 1;
    reach_regression_coeff_other_reach = 1.0;
    norisk_ratio_if_other_reach = 0.0;
    dora_fuuro_coeff = 1.0;
    other_end_prob_max = 1.0;
    reach_tenpai_prob_other_coeff = 1.0;
    other_end_prob_coeff_if_other_reach = 1.0;
    last_tedashi_neighbor_coeff = 1.0;
    gukei_est_coeff = 0.2;
    last_effective_ratio = 1.0;
    tsumo_num_DP_max_not_menzen = 20;
    fuuro_num_max = 3;
    cn_max_addition = 0;
    enumerate_restriction = -1;
    enumerate_restriction_fp = -1;
    tsumo_enumerate_always = -1;
    tsumo_enumerate_fuuro_restriction = -1;
    tsumo_enumerate_restriction = 20000;

    tsumo_enumerate_additional_maximum = 0;
    tsumo_enumerate_additional_minimum = 0;
    tsumo_enumerate_additional_priority = 0.0;

    for (int han = 0; han < 14; han++) {
        for (int fu = 0; fu < 12; fu++) {
            hanfu_weight_tsumo[han][fu] = 0.0;
            hanfu_weight_ron[han][fu] = 0.0;
        }
    }
    hanfu_weight_tsumo[3][3] = 0.4;
    hanfu_weight_tsumo[4][3] = 0.5;
    hanfu_weight_tsumo[6][3] = 0.1;

    hanfu_weight_ron[2][3] = 0.1;
    hanfu_weight_ron[3][3] = 0.5;
    hanfu_weight_ron[4][3] = 0.4;
}

void Tactics::set_light(){
    tegawari_num[0] = 2;
    tegawari_num[1] = 1;
    tegawari_num[2] = 1;
    tegawari_num[3] = 0;
    tegawari_num[4] = 0;
    tegawari_num[5] = 0;
    tegawari_num[6] = 0;
    do_houjuu_discount = false;
    do_speed_modify = false;
    use_larger_at_cal_tenpai_after = false;
    betaori_compare_at_2fuuro = false;
    do_kan = true;
    do_kyushukyuhai = false;
    use_nn_keiten_estimator = false;
    use_nn_kyoku_result_target_estimator = false;
    use_nn_kyoku_result_other_agari_estimator = false;
    use_ori_choice_exception = false;
    use_new_agari_ml = false;
    use_agari_coeff_old = false;
    use_agari_coeff_tp = false;
    use_agari_coeff_fp = false;
    modify_always = false;
    use_rule_base_at_mentu5_titoi3_shanten = true;
    use_cn_max_addition_if_honitsu = false;
    use_reach_daten_data_flag = false;
    do_tsumo_prob_dora_shift = false;
    use_no_fuuro_data_flag = false;
    use_new_other_end_prob = true;
    use_fuuro_choice_simple = false;
    use_tenpai_prob_other_zero_fuuro_exception = false;
    use_ori_choice_exception_near_lose = false;
    use_reach_tenpai_prob_other_if_other_reach = true;
    use_han_shift_at_fuuro_estimation = false;
    use_han_shift_at_fuuro_estimation2 = false;
    use_new_tenpai_est_tmp = false;
    use_ratio_tas_to_coeff = true;
    use_ori_exp_at_dp_fuuro = true;
    jun_calc_bug = false;
    use_yama_ratio_kawa_num = 100;
    use_dp_last_tsumo_num = 0;
    jun_est_type = JET_DEFAULT;
    inclusive_sn_always = 1;
    inclusive_sn_other_reach = 2;
    inclusive_sn_fp = 1;
    inclusive_sn_fp_other_reach = 2;
    reach_regression_mode_default = 1;
    reach_regression_mode_other_reach = 1;
    reach_regression_coeff_other_reach = 1.0;
    norisk_ratio_if_other_reach = 0.0;
    dora_fuuro_coeff = 1.0;
    other_end_prob_max = 1.0;
    reach_tenpai_prob_other_coeff = 1.0;
    other_end_prob_coeff_if_other_reach = 1.0;
    last_tedashi_neighbor_coeff = 1.0;
    gukei_est_coeff = 0.2;
    last_effective_ratio = 1.0;
    tsumo_num_DP_max_not_menzen = 20;
    fuuro_num_max = 3;
    cn_max_addition = 0;
    enumerate_restriction = 50000;
    enumerate_restriction_fp = 50000;
    tsumo_enumerate_always = 5000;
    tsumo_enumerate_fuuro_restriction = 40000;
    tsumo_enumerate_restriction = 20000;

    tsumo_enumerate_additional_maximum = 0;
    tsumo_enumerate_additional_minimum = 0;
    tsumo_enumerate_additional_priority = 0.0;

    for (int han = 0; han < 14; han++) {
        for (int fu = 0; fu < 12; fu++) {
        hanfu_weight_tsumo[han][fu] = 0.0;
        hanfu_weight_ron[han][fu] = 0.0;
        }
    }
    hanfu_weight_tsumo[3][3] = 0.4;
    hanfu_weight_tsumo[4][3] = 0.5;
    hanfu_weight_tsumo[6][3] = 0.1;
    
    hanfu_weight_ron[2][3] = 0.1;
    hanfu_weight_ron[3][3] = 0.5;
    hanfu_weight_ron[4][3] = 0.4;
}

void Tactics::set_zero_first(){
    tegawari_num[0] = 2;
    tegawari_num[1] = 1;
    tegawari_num[2] = 1;
    tegawari_num[3] = 1;
    tegawari_num[4] = 0;
    tegawari_num[5] = 0;
    tegawari_num[6] = 0;
    do_houjuu_discount = false;
    do_speed_modify = false;
    use_larger_at_cal_tenpai_after = false;
    betaori_compare_at_2fuuro = false;
    do_kan = true;
    do_kyushukyuhai = false;
    use_nn_keiten_estimator = false;
    use_nn_kyoku_result_target_estimator = false;
    use_nn_kyoku_result_other_agari_estimator = false;
    use_ori_choice_exception = false;
    use_new_agari_ml = false;
    use_agari_coeff_old = false;
    use_agari_coeff_tp = false;
    use_agari_coeff_fp = false;
    modify_always = false;
    use_rule_base_at_mentu5_titoi3_shanten = true;
    use_cn_max_addition_if_honitsu = false;
    use_reach_daten_data_flag = false;
    do_tsumo_prob_dora_shift = false;
    use_no_fuuro_data_flag = false;
    use_new_other_end_prob = true;
    use_fuuro_choice_simple = false;
    use_tenpai_prob_other_zero_fuuro_exception = false;
    use_ori_choice_exception_near_lose = false;
    use_reach_tenpai_prob_other_if_other_reach = true;
    use_han_shift_at_fuuro_estimation = false;
    use_han_shift_at_fuuro_estimation2 = false;
    use_new_tenpai_est_tmp = false;
    use_ratio_tas_to_coeff = true;
    use_ori_exp_at_dp_fuuro = true;
    jun_calc_bug = false;
    use_yama_ratio_kawa_num = 100;
    use_dp_last_tsumo_num = 0;
    jun_est_type = JET_DEFAULT;
    inclusive_sn_always = 1;
    inclusive_sn_other_reach = 2;
    inclusive_sn_fp = 1;
    inclusive_sn_fp_other_reach = 2;
    reach_regression_mode_default = 1;
    reach_regression_mode_other_reach = 1;
    reach_regression_coeff_other_reach = 1.0;
    norisk_ratio_if_other_reach = 0.0;
    dora_fuuro_coeff = 1.0;
    other_end_prob_max = 1.0;
    reach_tenpai_prob_other_coeff = 1.0;
    other_end_prob_coeff_if_other_reach = 1.0;
    last_tedashi_neighbor_coeff = 1.0;
    gukei_est_coeff = 0.2;
    last_effective_ratio = 1.0;
    tsumo_num_DP_max_not_menzen = 20;
    fuuro_num_max = 3;
    cn_max_addition = 0;
    enumerate_restriction = 30000;
    enumerate_restriction_fp = 30000;
    tsumo_enumerate_always = 2000;
    tsumo_enumerate_fuuro_restriction = 20000;
    tsumo_enumerate_restriction = 10000;

    tsumo_enumerate_additional_maximum = 0;
    tsumo_enumerate_additional_minimum = 0;
    tsumo_enumerate_additional_priority = 0.0;

    for (int han = 0; han < 14; han++) {
        for (int fu = 0; fu < 12; fu++) {
        hanfu_weight_tsumo[han][fu] = 0.0;
        hanfu_weight_ron[han][fu] = 0.0;
        }
    }
    hanfu_weight_tsumo[3][3] = 0.4;
    hanfu_weight_tsumo[4][3] = 0.5;
    hanfu_weight_tsumo[6][3] = 0.1;
    
    hanfu_weight_ron[2][3] = 0.1;
    hanfu_weight_ron[3][3] = 0.5;
    hanfu_weight_ron[4][3] = 0.4;
}

int cal_titoi_change_num_max(const int titoi_shanten_num, const int mentu_shanten_num) {
	if (titoi_shanten_num <= mentu_shanten_num) {
		if (titoi_shanten_num <= 2) {
			return titoi_shanten_num + 1;
		} else {
			return titoi_shanten_num;
		}
	} else if (titoi_shanten_num + 1 <= mentu_shanten_num) {
		return titoi_shanten_num;
	} else {
		return 0;
	}
}

bool cal_dp_flag(const int shanten_num, const int fuuro_agari_shanten_num, const bool is_other_reach_declared, const bool is_fuuro_phase, const Tactics& tactics) {
    if (shanten_num <= tactics.inclusive_sn_always) {
        return true;
    }
    if (is_other_reach_declared) {
        if (shanten_num <= tactics.inclusive_sn_other_reach) {
            return true;
        }
    }
    if (is_fuuro_phase && shanten_num <= tactics.inclusive_sn_fp) {
        return true;
    }
    if (is_other_reach_declared && is_fuuro_phase) {
        if (shanten_num <= tactics.inclusive_sn_fp_other_reach) {
            return true;
        }
    }

    if (fuuro_agari_shanten_num <= tactics.inclusive_sn_always) {
        return true;
    }
    if (is_other_reach_declared) {
        if (fuuro_agari_shanten_num <= tactics.inclusive_sn_other_reach) {
            return true;
        }
    }
    
    if (fuuro_agari_shanten_num <= tactics.inclusive_sn_fp) {
        return true;
    }

    if (is_other_reach_declared && is_fuuro_phase) {
        if (fuuro_agari_shanten_num <= tactics.inclusive_sn_fp_other_reach) {
            return true;
        }
    }
    return false;
}
		
bool judge_kan(const int shanten_num, const bool is_other_reach_declared) {
    if (is_other_reach_declared && 2 <= shanten_num) {
        return false;
    }
    return true;
}		

		