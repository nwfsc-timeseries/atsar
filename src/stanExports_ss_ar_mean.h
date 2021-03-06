// Generated by rstantools.  Do not edit by hand.

/*
    atsarpackage is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    atsarpackage is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with atsarpackage.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.21.0
#include <stan/model/model_header.hpp>
namespace model_ss_ar_mean_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_ss_ar_mean");
    reader.add_event(78, 76, "end", "model_ss_ar_mean");
    return reader;
}
#include <stan_meta_header.hpp>
class model_ss_ar_mean
  : public stan::model::model_base_crtp<model_ss_ar_mean> {
private:
        int N;
        int n_pos;
        vector_d y;
        std::vector<int> y_int;
        std::vector<int> pos_indx;
        int est_nu;
        int family;
public:
    model_ss_ar_mean(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_ss_ar_mean(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_ss_ar_mean_namespace::model_ss_ar_mean";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 2;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            check_greater_or_equal(function__, "N", N, 0);
            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "n_pos", "int", context__.to_vec());
            n_pos = int(0);
            vals_i__ = context__.vals_i("n_pos");
            pos__ = 0;
            n_pos = vals_i__[pos__++];
            check_greater_or_equal(function__, "n_pos", n_pos, 0);
            current_statement_begin__ = 4;
            validate_non_negative_index("y", "n_pos", n_pos);
            context__.validate_dims("data initialization", "y", "vector_d", context__.to_vec(n_pos));
            y = Eigen::Matrix<double, Eigen::Dynamic, 1>(n_pos);
            vals_r__ = context__.vals_r("y");
            pos__ = 0;
            size_t y_j_1_max__ = n_pos;
            for (size_t j_1__ = 0; j_1__ < y_j_1_max__; ++j_1__) {
                y(j_1__) = vals_r__[pos__++];
            }
            current_statement_begin__ = 5;
            validate_non_negative_index("y_int", "n_pos", n_pos);
            context__.validate_dims("data initialization", "y_int", "int", context__.to_vec(n_pos));
            y_int = std::vector<int>(n_pos, int(0));
            vals_i__ = context__.vals_i("y_int");
            pos__ = 0;
            size_t y_int_k_0_max__ = n_pos;
            for (size_t k_0__ = 0; k_0__ < y_int_k_0_max__; ++k_0__) {
                y_int[k_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 6;
            validate_non_negative_index("pos_indx", "(n_pos + 2)", (n_pos + 2));
            context__.validate_dims("data initialization", "pos_indx", "int", context__.to_vec((n_pos + 2)));
            pos_indx = std::vector<int>((n_pos + 2), int(0));
            vals_i__ = context__.vals_i("pos_indx");
            pos__ = 0;
            size_t pos_indx_k_0_max__ = (n_pos + 2);
            for (size_t k_0__ = 0; k_0__ < pos_indx_k_0_max__; ++k_0__) {
                pos_indx[k_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 7;
            context__.validate_dims("data initialization", "est_nu", "int", context__.to_vec());
            est_nu = int(0);
            vals_i__ = context__.vals_i("est_nu");
            pos__ = 0;
            est_nu = vals_i__[pos__++];
            check_greater_or_equal(function__, "est_nu", est_nu, 0);
            current_statement_begin__ = 8;
            context__.validate_dims("data initialization", "family", "int", context__.to_vec());
            family = int(0);
            vals_i__ = context__.vals_i("family");
            pos__ = 0;
            family = vals_i__[pos__++];
            // initialize transformed data variables
            // execute transformed data statements
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 11;
            num_params_r__ += 1;
            current_statement_begin__ = 12;
            num_params_r__ += 1;
            current_statement_begin__ = 13;
            num_params_r__ += 1;
            current_statement_begin__ = 14;
            validate_non_negative_index("pro_dev", "(N - 1)", (N - 1));
            num_params_r__ += (N - 1);
            current_statement_begin__ = 15;
            num_params_r__ += 1;
            current_statement_begin__ = 16;
            num_params_r__ += 1;
            current_statement_begin__ = 17;
            validate_non_negative_index("nu", "est_nu", est_nu);
            num_params_r__ += (1 * est_nu);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_ss_ar_mean() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 11;
        if (!(context__.contains_r("x0")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable x0 missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("x0");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "x0", "double", context__.to_vec());
        double x0(0);
        x0 = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(x0);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable x0: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 12;
        if (!(context__.contains_r("phi")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable phi missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("phi");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "phi", "double", context__.to_vec());
        double phi(0);
        phi = vals_r__[pos__++];
        try {
            writer__.scalar_lub_unconstrain(-(0.999), 0.999, phi);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable phi: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 13;
        if (!(context__.contains_r("mu")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable mu missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("mu");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "mu", "double", context__.to_vec());
        double mu(0);
        mu = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(mu);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable mu: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 14;
        if (!(context__.contains_r("pro_dev")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable pro_dev missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("pro_dev");
        pos__ = 0U;
        validate_non_negative_index("pro_dev", "(N - 1)", (N - 1));
        context__.validate_dims("parameter initialization", "pro_dev", "vector_d", context__.to_vec((N - 1)));
        Eigen::Matrix<double, Eigen::Dynamic, 1> pro_dev((N - 1));
        size_t pro_dev_j_1_max__ = (N - 1);
        for (size_t j_1__ = 0; j_1__ < pro_dev_j_1_max__; ++j_1__) {
            pro_dev(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(pro_dev);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable pro_dev: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 15;
        if (!(context__.contains_r("sigma_process")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable sigma_process missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("sigma_process");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "sigma_process", "double", context__.to_vec());
        double sigma_process(0);
        sigma_process = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, sigma_process);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable sigma_process: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 16;
        if (!(context__.contains_r("sigma_obs")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable sigma_obs missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("sigma_obs");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "sigma_obs", "double", context__.to_vec());
        double sigma_obs(0);
        sigma_obs = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, sigma_obs);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable sigma_obs: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 17;
        if (!(context__.contains_r("nu")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable nu missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("nu");
        pos__ = 0U;
        validate_non_negative_index("nu", "est_nu", est_nu);
        context__.validate_dims("parameter initialization", "nu", "double", context__.to_vec(est_nu));
        std::vector<double> nu(est_nu, double(0));
        size_t nu_k_0_max__ = est_nu;
        for (size_t k_0__ = 0; k_0__ < nu_k_0_max__; ++k_0__) {
            nu[k_0__] = vals_r__[pos__++];
        }
        size_t nu_i_0_max__ = est_nu;
        for (size_t i_0__ = 0; i_0__ < nu_i_0_max__; ++i_0__) {
            try {
                writer__.scalar_lb_unconstrain(2, nu[i_0__]);
            } catch (const std::exception& e) {
                stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable nu: ") + e.what()), current_statement_begin__, prog_reader__());
            }
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 11;
            local_scalar_t__ x0;
            (void) x0;  // dummy to suppress unused var warning
            if (jacobian__)
                x0 = in__.scalar_constrain(lp__);
            else
                x0 = in__.scalar_constrain();
            current_statement_begin__ = 12;
            local_scalar_t__ phi;
            (void) phi;  // dummy to suppress unused var warning
            if (jacobian__)
                phi = in__.scalar_lub_constrain(-(0.999), 0.999, lp__);
            else
                phi = in__.scalar_lub_constrain(-(0.999), 0.999);
            current_statement_begin__ = 13;
            local_scalar_t__ mu;
            (void) mu;  // dummy to suppress unused var warning
            if (jacobian__)
                mu = in__.scalar_constrain(lp__);
            else
                mu = in__.scalar_constrain();
            current_statement_begin__ = 14;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> pro_dev;
            (void) pro_dev;  // dummy to suppress unused var warning
            if (jacobian__)
                pro_dev = in__.vector_constrain((N - 1), lp__);
            else
                pro_dev = in__.vector_constrain((N - 1));
            current_statement_begin__ = 15;
            local_scalar_t__ sigma_process;
            (void) sigma_process;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_process = in__.scalar_lb_constrain(0, lp__);
            else
                sigma_process = in__.scalar_lb_constrain(0);
            current_statement_begin__ = 16;
            local_scalar_t__ sigma_obs;
            (void) sigma_obs;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_obs = in__.scalar_lb_constrain(0, lp__);
            else
                sigma_obs = in__.scalar_lb_constrain(0);
            current_statement_begin__ = 17;
            std::vector<local_scalar_t__> nu;
            size_t nu_d_0_max__ = est_nu;
            nu.reserve(nu_d_0_max__);
            for (size_t d_0__ = 0; d_0__ < nu_d_0_max__; ++d_0__) {
                if (jacobian__)
                    nu.push_back(in__.scalar_lb_constrain(2, lp__));
                else
                    nu.push_back(in__.scalar_lb_constrain(2));
            }
            // transformed parameters
            current_statement_begin__ = 20;
            validate_non_negative_index("pred", "N", N);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> pred(N);
            stan::math::initialize(pred, DUMMY_VAR__);
            stan::math::fill(pred, DUMMY_VAR__);
            // transformed parameters block statements
            current_statement_begin__ = 21;
            stan::model::assign(pred, 
                        stan::model::cons_list(stan::model::index_uni(1), stan::model::nil_index_list()), 
                        x0, 
                        "assigning variable pred");
            current_statement_begin__ = 22;
            for (int i = 2; i <= N; ++i) {
                current_statement_begin__ = 23;
                stan::model::assign(pred, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            ((mu + (phi * (get_base1(pred, (i - 1), "pred", 1) - mu))) + (sigma_process * get_base1(pro_dev, (i - 1), "pro_dev", 1))), 
                            "assigning variable pred");
            }
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 20;
            size_t pred_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < pred_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(pred(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: pred" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable pred: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            // model body
            current_statement_begin__ = 27;
            lp_accum__.add(normal_log<propto__>(x0, 0, 10));
            current_statement_begin__ = 28;
            lp_accum__.add(normal_log<propto__>(phi, 0, 10));
            current_statement_begin__ = 29;
            lp_accum__.add(normal_log<propto__>(mu, 0, 10));
            current_statement_begin__ = 30;
            if (as_bool(logical_eq(est_nu, 1))) {
                current_statement_begin__ = 31;
                lp_accum__.add(student_t_log<propto__>(nu, 3, 2, 2));
            }
            current_statement_begin__ = 33;
            lp_accum__.add(student_t_log<propto__>(sigma_process, 3, 0, 2));
            current_statement_begin__ = 34;
            lp_accum__.add(student_t_log<propto__>(sigma_obs, 3, 0, 2));
            current_statement_begin__ = 35;
            if (as_bool(logical_eq(est_nu, 0))) {
                current_statement_begin__ = 36;
                lp_accum__.add(std_normal_log<propto__>(pro_dev));
            } else {
                current_statement_begin__ = 38;
                lp_accum__.add(student_t_log<propto__>(pro_dev, nu, 0, 1));
            }
            current_statement_begin__ = 41;
            if (as_bool(logical_eq(family, 1))) {
                current_statement_begin__ = 42;
                for (int i = 1; i <= n_pos; ++i) {
                    current_statement_begin__ = 44;
                    lp_accum__.add(normal_log<propto__>(get_base1(y, i, "y", 1), get_base1(pred, get_base1(pos_indx, i, "pos_indx", 1), "pred", 1), sigma_obs));
                }
            }
            current_statement_begin__ = 47;
            if (as_bool(logical_eq(family, 2))) {
                current_statement_begin__ = 48;
                for (int i = 1; i <= n_pos; ++i) {
                    current_statement_begin__ = 49;
                    lp_accum__.add(bernoulli_logit_log<propto__>(get_base1(y_int, i, "y_int", 1), get_base1(pred, get_base1(pos_indx, i, "pos_indx", 1), "pred", 1)));
                }
            }
            current_statement_begin__ = 52;
            if (as_bool(logical_eq(family, 3))) {
                current_statement_begin__ = 53;
                for (int i = 1; i <= n_pos; ++i) {
                    current_statement_begin__ = 54;
                    lp_accum__.add(poisson_log_log<propto__>(get_base1(y_int, i, "y_int", 1), get_base1(pred, get_base1(pos_indx, i, "pos_indx", 1), "pred", 1)));
                }
            }
            current_statement_begin__ = 57;
            if (as_bool(logical_eq(family, 4))) {
                current_statement_begin__ = 58;
                for (int i = 1; i <= n_pos; ++i) {
                    current_statement_begin__ = 59;
                    lp_accum__.add(gamma_log<propto__>(get_base1(y, i, "y", 1), sigma_obs, (sigma_obs / stan::math::exp(get_base1(pred, get_base1(pos_indx, i, "pos_indx", 1), "pred", 1)))));
                }
            }
            current_statement_begin__ = 62;
            if (as_bool(logical_eq(family, 5))) {
                current_statement_begin__ = 63;
                for (int i = 1; i <= n_pos; ++i) {
                    current_statement_begin__ = 64;
                    lp_accum__.add(lognormal_log<propto__>(get_base1(y, i, "y", 1), get_base1(pred, get_base1(pos_indx, i, "pos_indx", 1), "pred", 1), sigma_obs));
                }
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("x0");
        names__.push_back("phi");
        names__.push_back("mu");
        names__.push_back("pro_dev");
        names__.push_back("sigma_process");
        names__.push_back("sigma_obs");
        names__.push_back("nu");
        names__.push_back("pred");
        names__.push_back("log_lik");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back((N - 1));
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(est_nu);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n_pos);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_ss_ar_mean_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        double x0 = in__.scalar_constrain();
        vars__.push_back(x0);
        double phi = in__.scalar_lub_constrain(-(0.999), 0.999);
        vars__.push_back(phi);
        double mu = in__.scalar_constrain();
        vars__.push_back(mu);
        Eigen::Matrix<double, Eigen::Dynamic, 1> pro_dev = in__.vector_constrain((N - 1));
        size_t pro_dev_j_1_max__ = (N - 1);
        for (size_t j_1__ = 0; j_1__ < pro_dev_j_1_max__; ++j_1__) {
            vars__.push_back(pro_dev(j_1__));
        }
        double sigma_process = in__.scalar_lb_constrain(0);
        vars__.push_back(sigma_process);
        double sigma_obs = in__.scalar_lb_constrain(0);
        vars__.push_back(sigma_obs);
        std::vector<double> nu;
        size_t nu_d_0_max__ = est_nu;
        nu.reserve(nu_d_0_max__);
        for (size_t d_0__ = 0; d_0__ < nu_d_0_max__; ++d_0__) {
            nu.push_back(in__.scalar_lb_constrain(2));
        }
        size_t nu_k_0_max__ = est_nu;
        for (size_t k_0__ = 0; k_0__ < nu_k_0_max__; ++k_0__) {
            vars__.push_back(nu[k_0__]);
        }
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            // declare and define transformed parameters
            current_statement_begin__ = 20;
            validate_non_negative_index("pred", "N", N);
            Eigen::Matrix<double, Eigen::Dynamic, 1> pred(N);
            stan::math::initialize(pred, DUMMY_VAR__);
            stan::math::fill(pred, DUMMY_VAR__);
            // do transformed parameters statements
            current_statement_begin__ = 21;
            stan::model::assign(pred, 
                        stan::model::cons_list(stan::model::index_uni(1), stan::model::nil_index_list()), 
                        x0, 
                        "assigning variable pred");
            current_statement_begin__ = 22;
            for (int i = 2; i <= N; ++i) {
                current_statement_begin__ = 23;
                stan::model::assign(pred, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            ((mu + (phi * (get_base1(pred, (i - 1), "pred", 1) - mu))) + (sigma_process * get_base1(pro_dev, (i - 1), "pro_dev", 1))), 
                            "assigning variable pred");
            }
            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            // write transformed parameters
            if (include_tparams__) {
                size_t pred_j_1_max__ = N;
                for (size_t j_1__ = 0; j_1__ < pred_j_1_max__; ++j_1__) {
                    vars__.push_back(pred(j_1__));
                }
            }
            if (!include_gqs__) return;
            // declare and define generated quantities
            current_statement_begin__ = 69;
            validate_non_negative_index("log_lik", "n_pos", n_pos);
            Eigen::Matrix<double, Eigen::Dynamic, 1> log_lik(n_pos);
            stan::math::initialize(log_lik, DUMMY_VAR__);
            stan::math::fill(log_lik, DUMMY_VAR__);
            // generated quantities statements
            current_statement_begin__ = 71;
            if (as_bool(logical_eq(family, 1))) {
                current_statement_begin__ = 71;
                for (int n = 1; n <= n_pos; ++n) {
                    current_statement_begin__ = 71;
                    stan::model::assign(log_lik, 
                                stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                                normal_log(get_base1(y, n, "y", 1), get_base1(pred, get_base1(pos_indx, n, "pos_indx", 1), "pred", 1), sigma_obs), 
                                "assigning variable log_lik");
                }
            }
            current_statement_begin__ = 72;
            if (as_bool(logical_eq(family, 2))) {
                current_statement_begin__ = 72;
                for (int n = 1; n <= n_pos; ++n) {
                    current_statement_begin__ = 72;
                    stan::model::assign(log_lik, 
                                stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                                bernoulli_log(get_base1(y_int, n, "y_int", 1), inv_logit(get_base1(pred, get_base1(pos_indx, n, "pos_indx", 1), "pred", 1))), 
                                "assigning variable log_lik");
                }
            }
            current_statement_begin__ = 73;
            if (as_bool(logical_eq(family, 3))) {
                current_statement_begin__ = 73;
                for (int n = 1; n <= n_pos; ++n) {
                    current_statement_begin__ = 73;
                    stan::model::assign(log_lik, 
                                stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                                poisson_log(get_base1(y_int, n, "y_int", 1), stan::math::exp(get_base1(pred, get_base1(pos_indx, n, "pos_indx", 1), "pred", 1))), 
                                "assigning variable log_lik");
                }
            }
            current_statement_begin__ = 74;
            if (as_bool(logical_eq(family, 4))) {
                current_statement_begin__ = 74;
                for (int n = 1; n <= n_pos; ++n) {
                    current_statement_begin__ = 74;
                    stan::model::assign(log_lik, 
                                stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                                gamma_log(get_base1(y, n, "y", 1), sigma_obs, (sigma_obs / stan::math::exp(get_base1(pred, get_base1(pos_indx, n, "pos_indx", 1), "pred", 1)))), 
                                "assigning variable log_lik");
                }
            }
            current_statement_begin__ = 75;
            if (as_bool(logical_eq(family, 5))) {
                current_statement_begin__ = 75;
                for (int n = 1; n <= n_pos; ++n) {
                    current_statement_begin__ = 75;
                    stan::model::assign(log_lik, 
                                stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                                lognormal_log(get_base1(y, n, "y", 1), get_base1(pred, get_base1(pos_indx, n, "pos_indx", 1), "pred", 1), sigma_obs), 
                                "assigning variable log_lik");
                }
            }
            // validate, write generated quantities
            current_statement_begin__ = 69;
            size_t log_lik_j_1_max__ = n_pos;
            for (size_t j_1__ = 0; j_1__ < log_lik_j_1_max__; ++j_1__) {
                vars__.push_back(log_lik(j_1__));
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    std::string model_name() const {
        return "model_ss_ar_mean";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "x0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "phi";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu";
        param_names__.push_back(param_name_stream__.str());
        size_t pro_dev_j_1_max__ = (N - 1);
        for (size_t j_1__ = 0; j_1__ < pro_dev_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "pro_dev" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_process";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_obs";
        param_names__.push_back(param_name_stream__.str());
        size_t nu_k_0_max__ = est_nu;
        for (size_t k_0__ = 0; k_0__ < nu_k_0_max__; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "nu" << '.' << k_0__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t pred_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < pred_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "pred" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
        size_t log_lik_j_1_max__ = n_pos;
        for (size_t j_1__ = 0; j_1__ < log_lik_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "log_lik" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "x0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "phi";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu";
        param_names__.push_back(param_name_stream__.str());
        size_t pro_dev_j_1_max__ = (N - 1);
        for (size_t j_1__ = 0; j_1__ < pro_dev_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "pro_dev" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_process";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_obs";
        param_names__.push_back(param_name_stream__.str());
        size_t nu_k_0_max__ = est_nu;
        for (size_t k_0__ = 0; k_0__ < nu_k_0_max__; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "nu" << '.' << k_0__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t pred_j_1_max__ = N;
            for (size_t j_1__ = 0; j_1__ < pred_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "pred" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
        size_t log_lik_j_1_max__ = n_pos;
        for (size_t j_1__ = 0; j_1__ < log_lik_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "log_lik" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
    }
}; // model
}  // namespace
typedef model_ss_ar_mean_namespace::model_ss_ar_mean stan_model;
#ifndef USING_R
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}
#endif
#endif
