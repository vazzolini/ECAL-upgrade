#ifndef ISL_POLYNOMIAL_H
#define ISL_POLYNOMIAL_H

#include <isl/ctx.h>
#include <isl/constraint.h>
#include <isl/dim.h>
#include <isl/div.h>
#include <isl/set.h>
#include <isl/point.h>
#include <isl/printer.h>
#include <isl/union_set.h>

#if defined(__cplusplus)
extern "C" {
#endif

struct isl_qpolynomial;
typedef struct isl_qpolynomial isl_qpolynomial;

isl_ctx *isl_qpolynomial_get_ctx(__isl_keep isl_qpolynomial *qp);
__isl_give isl_dim *isl_qpolynomial_get_dim(__isl_keep isl_qpolynomial *qp);
__isl_give isl_qpolynomial *isl_qpolynomial_reset_dim(
	__isl_take isl_qpolynomial *qp, __isl_take isl_dim *dim);
unsigned isl_qpolynomial_dim(__isl_keep isl_qpolynomial *qp,
	enum isl_dim_type type);
int isl_qpolynomial_involves_dims(__isl_keep isl_qpolynomial *qp,
	enum isl_dim_type type, unsigned first, unsigned n);

__isl_give isl_qpolynomial *isl_qpolynomial_set_dim_name(
	__isl_take isl_qpolynomial *qp,
	enum isl_dim_type type, unsigned pos, const char *s);

__isl_give isl_qpolynomial *isl_qpolynomial_zero(__isl_take isl_dim *dim);
__isl_give isl_qpolynomial *isl_qpolynomial_one(__isl_take isl_dim *dim);
__isl_give isl_qpolynomial *isl_qpolynomial_infty(__isl_take isl_dim *dim);
__isl_give isl_qpolynomial *isl_qpolynomial_neginfty(__isl_take isl_dim *dim);
__isl_give isl_qpolynomial *isl_qpolynomial_nan(__isl_take isl_dim *dim);
__isl_give isl_qpolynomial *isl_qpolynomial_rat_cst(__isl_take isl_dim *dim,
	const isl_int n, const isl_int d);
__isl_give isl_qpolynomial *isl_qpolynomial_div(__isl_take isl_div *div);
__isl_give isl_qpolynomial *isl_qpolynomial_var(__isl_take isl_dim *dim,
	enum isl_dim_type type, unsigned pos);
__isl_give isl_qpolynomial *isl_qpolynomial_copy(__isl_keep isl_qpolynomial *qp);
void isl_qpolynomial_free(__isl_take isl_qpolynomial *qp);

int isl_qpolynomial_is_equal(__isl_keep isl_qpolynomial *qp1,
	__isl_keep isl_qpolynomial *qp2);
int isl_qpolynomial_is_zero(__isl_keep isl_qpolynomial *qp);
int isl_qpolynomial_is_nan(__isl_keep isl_qpolynomial *qp);
int isl_qpolynomial_is_infty(__isl_keep isl_qpolynomial *qp);
int isl_qpolynomial_is_neginfty(__isl_keep isl_qpolynomial *qp);
int isl_qpolynomial_sgn(__isl_keep isl_qpolynomial *qp);
int isl_qpolynomial_is_cst(__isl_keep isl_qpolynomial *qp,
	isl_int *n, isl_int *d);
void isl_qpolynomial_get_den(__isl_keep isl_qpolynomial *qp, isl_int *d);

__isl_give isl_qpolynomial *isl_qpolynomial_neg(__isl_take isl_qpolynomial *qp);
__isl_give isl_qpolynomial *isl_qpolynomial_add(__isl_take isl_qpolynomial *qp1,
	__isl_take isl_qpolynomial *qp2);
__isl_give isl_qpolynomial *isl_qpolynomial_sub(__isl_take isl_qpolynomial *qp1,
	__isl_take isl_qpolynomial *qp2);
__isl_give isl_qpolynomial *isl_qpolynomial_mul(__isl_take isl_qpolynomial *qp1,
	__isl_take isl_qpolynomial *qp2);
__isl_give isl_qpolynomial *isl_qpolynomial_pow(__isl_take isl_qpolynomial *qp,
	unsigned power);
__isl_give isl_qpolynomial *isl_qpolynomial_add_isl_int(
	__isl_take isl_qpolynomial *qp, isl_int v);
__isl_give isl_qpolynomial *isl_qpolynomial_mul_isl_int(
	__isl_take isl_qpolynomial *qp, isl_int v);

__isl_give isl_qpolynomial *isl_qpolynomial_insert_dims(
	__isl_take isl_qpolynomial *qp, enum isl_dim_type type,
	unsigned first, unsigned n);
__isl_give isl_qpolynomial *isl_qpolynomial_add_dims(
	__isl_take isl_qpolynomial *qp, enum isl_dim_type type, unsigned n);
__isl_give isl_qpolynomial *isl_qpolynomial_move_dims(
	__isl_take isl_qpolynomial *qp,
	enum isl_dim_type dst_type, unsigned dst_pos,
	enum isl_dim_type src_type, unsigned src_pos, unsigned n);
__isl_give isl_qpolynomial *isl_qpolynomial_drop_dims(
	__isl_take isl_qpolynomial *qp,
	enum isl_dim_type type, unsigned first, unsigned n);

__isl_give isl_qpolynomial *isl_qpolynomial_substitute(
	__isl_take isl_qpolynomial *qp,
	enum isl_dim_type type, unsigned first, unsigned n,
	__isl_keep isl_qpolynomial **subs);

int isl_qpolynomial_as_polynomial_on_domain(__isl_keep isl_qpolynomial *qp,
	__isl_keep isl_basic_set *bset,
	int (*fn)(__isl_take isl_basic_set *bset,
		  __isl_take isl_qpolynomial *poly, void *user), void *user);

__isl_give isl_qpolynomial *isl_qpolynomial_homogenize(
	__isl_take isl_qpolynomial *poly);

struct isl_term;
typedef struct isl_term isl_term;

isl_ctx *isl_term_get_ctx(__isl_keep isl_term *term);

void isl_term_free(__isl_take isl_term *term);

unsigned isl_term_dim(__isl_keep isl_term *term, enum isl_dim_type type);
void isl_term_get_num(__isl_keep isl_term *term, isl_int *n);
void isl_term_get_den(__isl_keep isl_term *term, isl_int *d);
int isl_term_get_exp(__isl_keep isl_term *term,
	enum isl_dim_type type, unsigned pos);
__isl_give isl_div *isl_term_get_div(__isl_keep isl_term *term, unsigned pos);

int isl_qpolynomial_foreach_term(__isl_keep isl_qpolynomial *qp,
	int (*fn)(__isl_take isl_term *term, void *user), void *user);

__isl_give isl_qpolynomial *isl_qpolynomial_eval(
	__isl_take isl_qpolynomial *qp, __isl_take isl_point *pnt);

__isl_give isl_qpolynomial *isl_qpolynomial_from_constraint(
	__isl_take isl_constraint *c, enum isl_dim_type type, unsigned pos);
__isl_give isl_qpolynomial *isl_qpolynomial_from_term(__isl_take isl_term *term);
__isl_give isl_basic_map *isl_basic_map_from_qpolynomial(
	__isl_take isl_qpolynomial *qp);

__isl_give isl_printer *isl_printer_print_qpolynomial(
	__isl_take isl_printer *p, __isl_keep isl_qpolynomial *qp);
void isl_qpolynomial_print(__isl_keep isl_qpolynomial *qp, FILE *out,
	unsigned output_format);
void isl_qpolynomial_dump(__isl_keep isl_qpolynomial *qp);

struct isl_pw_qpolynomial;
typedef struct isl_pw_qpolynomial isl_pw_qpolynomial;

isl_ctx *isl_pw_qpolynomial_get_ctx(__isl_keep isl_pw_qpolynomial *pwqp);

__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_zero(__isl_take isl_dim *dim);
__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_alloc(__isl_take isl_set *set,
	__isl_take isl_qpolynomial *qp);
__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_copy(
	__isl_keep isl_pw_qpolynomial *pwqp);
void isl_pw_qpolynomial_free(__isl_take isl_pw_qpolynomial *pwqp);

int isl_pw_qpolynomial_is_zero(__isl_keep isl_pw_qpolynomial *pwqp);

__isl_give isl_dim *isl_pw_qpolynomial_get_dim(
	__isl_keep isl_pw_qpolynomial *pwqp);
__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_reset_dim(
	__isl_take isl_pw_qpolynomial *pwqp, __isl_take isl_dim *dim);
unsigned isl_pw_qpolynomial_dim(__isl_keep isl_pw_qpolynomial *pwqp,
	enum isl_dim_type type);
int isl_pw_qpolynomial_involves_dims(__isl_keep isl_pw_qpolynomial *pwqp,
	enum isl_dim_type type, unsigned first, unsigned n);
int isl_pw_qpolynomial_has_equal_dim(__isl_keep isl_pw_qpolynomial *pwqp1,
	__isl_keep isl_pw_qpolynomial *pwqp2);

__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_set_dim_name(
	__isl_take isl_pw_qpolynomial *pwqp,
	enum isl_dim_type type, unsigned pos, const char *s);

__isl_give isl_set *isl_pw_qpolynomial_domain(__isl_take isl_pw_qpolynomial *pwqp);
__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_intersect_domain(
	__isl_take isl_pw_qpolynomial *pwpq, __isl_take isl_set *set);

__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_drop_dims(
	__isl_take isl_pw_qpolynomial *pwqp,
	enum isl_dim_type type, unsigned first, unsigned n);
__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_split_dims(
	__isl_take isl_pw_qpolynomial *pwqp,
	enum isl_dim_type type, unsigned first, unsigned n);

__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_add(
	__isl_take isl_pw_qpolynomial *pwqp1,
	__isl_take isl_pw_qpolynomial *pwqp2);
__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_sub(
	__isl_take isl_pw_qpolynomial *pwqp1,
	__isl_take isl_pw_qpolynomial *pwqp2);
__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_add_disjoint(
	__isl_take isl_pw_qpolynomial *pwqp1,
	__isl_take isl_pw_qpolynomial *pwqp2);
__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_neg(
	__isl_take isl_pw_qpolynomial *pwqp);
__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_mul(
	__isl_take isl_pw_qpolynomial *pwqp1,
	__isl_take isl_pw_qpolynomial *pwqp2);
__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_mul_isl_int(
	__isl_take isl_pw_qpolynomial *pwqp, isl_int v);

__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_insert_dims(
	__isl_take isl_pw_qpolynomial *pwqp, enum isl_dim_type type,
	unsigned first, unsigned n);
__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_add_dims(
	__isl_take isl_pw_qpolynomial *pwqp,
	enum isl_dim_type type, unsigned n);
__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_move_dims(
	__isl_take isl_pw_qpolynomial *pwqp,
	enum isl_dim_type dst_type, unsigned dst_pos,
	enum isl_dim_type src_type, unsigned src_pos, unsigned n);

__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_fix_dim(
	__isl_take isl_pw_qpolynomial *pwqp,
	enum isl_dim_type type, unsigned n, isl_int v);

__isl_give isl_qpolynomial *isl_pw_qpolynomial_eval(
	__isl_take isl_pw_qpolynomial *pwqp, __isl_take isl_point *pnt);

__isl_give isl_qpolynomial *isl_pw_qpolynomial_max(
	__isl_take isl_pw_qpolynomial *pwqp);
__isl_give isl_qpolynomial *isl_pw_qpolynomial_min(
	__isl_take isl_pw_qpolynomial *pwqp);

int isl_pw_qpolynomial_foreach_piece(__isl_keep isl_pw_qpolynomial *pwqp,
	int (*fn)(__isl_take isl_set *set, __isl_take isl_qpolynomial *qp,
		    void *user), void *user);
int isl_pw_qpolynomial_foreach_lifted_piece(__isl_keep isl_pw_qpolynomial *pwqp,
	int (*fn)(__isl_take isl_set *set, __isl_take isl_qpolynomial *qp,
		    void *user), void *user);

__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_read_from_str(isl_ctx *ctx,
		const char *str);
__isl_give isl_printer *isl_printer_print_pw_qpolynomial(
	__isl_take isl_printer *p, __isl_keep isl_pw_qpolynomial *pwqp);
void isl_pw_qpolynomial_print(__isl_keep isl_pw_qpolynomial *pwqp, FILE *out,
	unsigned output_format);
void isl_pw_qpolynomial_dump(__isl_keep isl_pw_qpolynomial *pwqp);

__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_coalesce(
	__isl_take isl_pw_qpolynomial *pwqp);
__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_gist(
	__isl_take isl_pw_qpolynomial *pwqp, __isl_take isl_set *context);

__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_split_periods(
	__isl_take isl_pw_qpolynomial *pwqp, int max_periods);

__isl_give isl_pw_qpolynomial *isl_basic_set_multiplicative_call(
	__isl_take isl_basic_set *bset,
	__isl_give isl_pw_qpolynomial *(*fn)(__isl_take isl_basic_set *bset));

enum isl_fold {
	isl_fold_min,
	isl_fold_max,
	isl_fold_list
};

struct isl_qpolynomial_fold;
typedef struct isl_qpolynomial_fold isl_qpolynomial_fold;

isl_ctx *isl_qpolynomial_fold_get_ctx(__isl_keep isl_qpolynomial_fold *fold);
enum isl_fold isl_qpolynomial_fold_get_type(__isl_keep isl_qpolynomial_fold *fold);

__isl_give isl_qpolynomial_fold *isl_qpolynomial_fold_empty(enum isl_fold type,
	__isl_take isl_dim *dim);
__isl_give isl_qpolynomial_fold *isl_qpolynomial_fold_alloc(
	enum isl_fold type, __isl_take isl_qpolynomial *qp);
__isl_give isl_qpolynomial_fold *isl_qpolynomial_fold_copy(
	__isl_keep isl_qpolynomial_fold *fold);
void isl_qpolynomial_fold_free(__isl_take isl_qpolynomial_fold *fold);

__isl_give isl_qpolynomial_fold *isl_qpolynomial_fold_reset_dim(
	__isl_take isl_qpolynomial_fold *fold, __isl_take isl_dim *dim);

int isl_qpolynomial_fold_is_empty(__isl_keep isl_qpolynomial_fold *fold);
int isl_qpolynomial_fold_is_equal(__isl_keep isl_qpolynomial_fold *fold1,
	__isl_keep isl_qpolynomial_fold *fold2);

__isl_give isl_qpolynomial_fold *isl_qpolynomial_fold_fold(
	__isl_take isl_qpolynomial_fold *fold1,
	__isl_take isl_qpolynomial_fold *fold2);

__isl_give isl_qpolynomial_fold *isl_qpolynomial_fold_mul_isl_int(
	__isl_take isl_qpolynomial_fold *fold, isl_int v);

__isl_give isl_qpolynomial_fold *isl_qpolynomial_fold_move_dims(
	__isl_take isl_qpolynomial_fold *fold,
	enum isl_dim_type dst_type, unsigned dst_pos,
	enum isl_dim_type src_type, unsigned src_pos, unsigned n);

__isl_give isl_qpolynomial_fold *isl_qpolynomial_fold_substitute(
	__isl_take isl_qpolynomial_fold *fold,
	enum isl_dim_type type, unsigned first, unsigned n,
	__isl_keep isl_qpolynomial **subs);

__isl_give isl_qpolynomial *isl_qpolynomial_fold_eval(
	__isl_take isl_qpolynomial_fold *fold, __isl_take isl_point *pnt);

int isl_qpolynomial_fold_foreach_qpolynomial(
	__isl_keep isl_qpolynomial_fold *fold,
	int (*fn)(__isl_take isl_qpolynomial *qp, void *user), void *user);

__isl_give isl_printer *isl_printer_print_qpolynomial_fold(
	__isl_take isl_printer *p, __isl_keep isl_qpolynomial_fold *fold);
void isl_qpolynomial_fold_print(__isl_keep isl_qpolynomial_fold *fold, FILE *out,
	unsigned output_format);
void isl_qpolynomial_fold_dump(__isl_keep isl_qpolynomial_fold *fold);

struct isl_pw_qpolynomial_fold;
typedef struct isl_pw_qpolynomial_fold isl_pw_qpolynomial_fold;

isl_ctx *isl_pw_qpolynomial_fold_get_ctx(__isl_keep isl_pw_qpolynomial_fold *pwf);

__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_from_pw_qpolynomial(
	enum isl_fold type, __isl_take isl_pw_qpolynomial *pwqp);

__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_alloc(
	enum isl_fold type,
	__isl_take isl_set *set, __isl_take isl_qpolynomial_fold *fold);
__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_copy(
	__isl_keep isl_pw_qpolynomial_fold *pwf);
void isl_pw_qpolynomial_fold_free(__isl_take isl_pw_qpolynomial_fold *pwf);

int isl_pw_qpolynomial_fold_is_zero(__isl_keep isl_pw_qpolynomial_fold *pwf);

__isl_give isl_dim *isl_pw_qpolynomial_fold_get_dim(
	__isl_keep isl_pw_qpolynomial_fold *pwf);
__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_reset_dim(
	__isl_take isl_pw_qpolynomial_fold *pwf, __isl_take isl_dim *dim);
unsigned isl_pw_qpolynomial_fold_dim(__isl_keep isl_pw_qpolynomial_fold *pwf,
	enum isl_dim_type type);
int isl_pw_qpolynomial_fold_has_equal_dim(
	__isl_keep isl_pw_qpolynomial_fold *pwf1,
	__isl_keep isl_pw_qpolynomial_fold *pwf2);

size_t isl_pw_qpolynomial_fold_size(__isl_keep isl_pw_qpolynomial_fold *pwf);

__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_zero(
	__isl_take isl_dim *dim, enum isl_fold type);

__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_set_dim_name(
	__isl_take isl_pw_qpolynomial_fold *pwf,
	enum isl_dim_type type, unsigned pos, const char *s);

__isl_give isl_set *isl_pw_qpolynomial_fold_domain(
	__isl_take isl_pw_qpolynomial_fold *pwf);
__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_intersect_domain(
	__isl_take isl_pw_qpolynomial_fold *pwf, __isl_take isl_set *set);

__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_add(
	__isl_take isl_pw_qpolynomial_fold *pwf1,
	__isl_take isl_pw_qpolynomial_fold *pwf2);
__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_fold(
	__isl_take isl_pw_qpolynomial_fold *pwf1,
	__isl_take isl_pw_qpolynomial_fold *pwf2);
__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_add_disjoint(
	__isl_take isl_pw_qpolynomial_fold *pwf1,
	__isl_take isl_pw_qpolynomial_fold *pwf2);
__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_mul_isl_int(
	__isl_take isl_pw_qpolynomial_fold *pwf, isl_int v);

__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_drop_dims(
	__isl_take isl_pw_qpolynomial_fold *pwf,
	enum isl_dim_type type, unsigned first, unsigned n);
__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_move_dims(
	__isl_take isl_pw_qpolynomial_fold *pwf,
	enum isl_dim_type dst_type, unsigned dst_pos,
	enum isl_dim_type src_type, unsigned src_pos, unsigned n);

__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_fix_dim(
	__isl_take isl_pw_qpolynomial_fold *pwf,
	enum isl_dim_type type, unsigned n, isl_int v);

__isl_give isl_qpolynomial *isl_pw_qpolynomial_fold_eval(
	__isl_take isl_pw_qpolynomial_fold *pwf, __isl_take isl_point *pnt);

int isl_pw_qpolynomial_fold_foreach_piece(
	__isl_keep isl_pw_qpolynomial_fold *pwf,
	int (*fn)(__isl_take isl_set *set, __isl_take isl_qpolynomial_fold *fold,
		    void *user), void *user);
int isl_pw_qpolynomial_fold_foreach_lifted_piece(
	__isl_keep isl_pw_qpolynomial_fold *pwf,
	int (*fn)(__isl_take isl_set *set, __isl_take isl_qpolynomial_fold *fold,
		    void *user), void *user);

__isl_give isl_printer *isl_printer_print_pw_qpolynomial_fold(
	__isl_take isl_printer *p, __isl_keep isl_pw_qpolynomial_fold *pwf);
void isl_pw_qpolynomial_fold_print(__isl_keep isl_pw_qpolynomial_fold *pwf,
	FILE *out, unsigned output_format);
void isl_pw_qpolynomial_fold_dump(__isl_keep isl_pw_qpolynomial_fold *pwf);

__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_coalesce(
	__isl_take isl_pw_qpolynomial_fold *pwf);
__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_gist(
	__isl_take isl_pw_qpolynomial_fold *pwf, __isl_take isl_set *context);

__isl_give isl_qpolynomial *isl_pw_qpolynomial_fold_max(
	__isl_take isl_pw_qpolynomial_fold *pwf);
__isl_give isl_qpolynomial *isl_pw_qpolynomial_fold_min(
	__isl_take isl_pw_qpolynomial_fold *pwf);

__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_bound(
	__isl_take isl_pw_qpolynomial *pwqp, enum isl_fold type, int *tight);
__isl_give isl_pw_qpolynomial_fold *isl_pw_qpolynomial_fold_bound(
	__isl_take isl_pw_qpolynomial_fold *pwf, int *tight);
__isl_give isl_pw_qpolynomial_fold *isl_set_apply_pw_qpolynomial_fold(
	__isl_take isl_set *set, __isl_take isl_pw_qpolynomial_fold *pwf,
	int *tight);
__isl_give isl_pw_qpolynomial_fold *isl_map_apply_pw_qpolynomial_fold(
	__isl_take isl_map *map, __isl_take isl_pw_qpolynomial_fold *pwf,
	int *tight);

__isl_give isl_pw_qpolynomial *isl_pw_qpolynomial_to_polynomial(
	__isl_take isl_pw_qpolynomial *pwqp, int sign);

struct isl_union_pw_qpolynomial;
typedef struct isl_union_pw_qpolynomial isl_union_pw_qpolynomial;

isl_ctx *isl_union_pw_qpolynomial_get_ctx(
	__isl_keep isl_union_pw_qpolynomial *upwqp);

__isl_give isl_union_pw_qpolynomial *isl_union_pw_qpolynomial_from_pw_qpolynomial(__isl_take isl_pw_qpolynomial *pwqp);
__isl_give isl_union_pw_qpolynomial *isl_union_pw_qpolynomial_zero(
	__isl_take isl_dim *dim);
__isl_give isl_union_pw_qpolynomial *isl_union_pw_qpolynomial_add_pw_qpolynomial(
	__isl_take isl_union_pw_qpolynomial *upwqp,
	__isl_take isl_pw_qpolynomial *pwqp);
__isl_give isl_union_pw_qpolynomial *isl_union_pw_qpolynomial_copy(
	__isl_keep isl_union_pw_qpolynomial *upwqp);
void isl_union_pw_qpolynomial_free(__isl_take isl_union_pw_qpolynomial *upwqp);

__isl_give isl_union_pw_qpolynomial *isl_union_pw_qpolynomial_add(
	__isl_take isl_union_pw_qpolynomial *upwqp1,
	__isl_take isl_union_pw_qpolynomial *upwqp2);
__isl_give isl_union_pw_qpolynomial *isl_union_pw_qpolynomial_sub(
	__isl_take isl_union_pw_qpolynomial *upwqp1,
	__isl_take isl_union_pw_qpolynomial *upwqp2);
__isl_give isl_union_pw_qpolynomial *isl_union_pw_qpolynomial_mul(
	__isl_take isl_union_pw_qpolynomial *upwqp1,
	__isl_take isl_union_pw_qpolynomial *upwqp2);
__isl_give isl_union_pw_qpolynomial *isl_union_pw_qpolynomial_mul_isl_int(
	__isl_take isl_union_pw_qpolynomial *upwqp, isl_int v);

__isl_give isl_union_set *isl_union_pw_qpolynomial_domain(
	__isl_take isl_union_pw_qpolynomial *upwqp);
__isl_give isl_union_pw_qpolynomial *isl_union_pw_qpolynomial_intersect_domain(
	__isl_take isl_union_pw_qpolynomial *upwpq,
	__isl_take isl_union_set *uset);

__isl_give isl_dim *isl_union_pw_qpolynomial_get_dim(
	__isl_keep isl_union_pw_qpolynomial *upwqp);

__isl_give isl_qpolynomial *isl_union_pw_qpolynomial_eval(
	__isl_take isl_union_pw_qpolynomial *upwqp, __isl_take isl_point *pnt);

__isl_give isl_union_pw_qpolynomial *isl_union_pw_qpolynomial_coalesce(
	__isl_take isl_union_pw_qpolynomial *upwqp);
__isl_give isl_union_pw_qpolynomial *isl_union_pw_qpolynomial_gist(
	__isl_take isl_union_pw_qpolynomial *upwqp,
	__isl_take isl_union_set *context);

__isl_give isl_union_pw_qpolynomial *isl_union_pw_qpolynomial_align_params(
	__isl_take isl_union_pw_qpolynomial *upwqp,
	__isl_take isl_dim *model);

int isl_union_pw_qpolynomial_foreach_pw_qpolynomial(
	__isl_keep isl_union_pw_qpolynomial *upwqp,
	int (*fn)(__isl_take isl_pw_qpolynomial *pwqp, void *user), void *user);
__isl_give isl_pw_qpolynomial *isl_union_pw_qpolynomial_extract_pw_qpolynomial(
	__isl_keep isl_union_pw_qpolynomial *upwqp, __isl_take isl_dim *dim);

__isl_give isl_printer *isl_printer_print_union_pw_qpolynomial(
	__isl_take isl_printer *p, __isl_keep isl_union_pw_qpolynomial *upwqp);

struct isl_union_pw_qpolynomial_fold;
typedef struct isl_union_pw_qpolynomial_fold isl_union_pw_qpolynomial_fold;

isl_ctx *isl_union_pw_qpolynomial_fold_get_ctx(
	__isl_keep isl_union_pw_qpolynomial_fold *upwf);

__isl_give isl_union_pw_qpolynomial_fold *isl_union_pw_qpolynomial_fold_from_pw_qpolynomial_fold(__isl_take isl_pw_qpolynomial_fold *pwf);
__isl_give isl_union_pw_qpolynomial_fold *isl_union_pw_qpolynomial_fold_zero(
	__isl_take isl_dim *dim, enum isl_fold type);
__isl_give isl_union_pw_qpolynomial_fold *isl_union_pw_qpolynomial_fold_fold_pw_qpolynomial_fold(
	__isl_take isl_union_pw_qpolynomial_fold *upwqp,
	__isl_take isl_pw_qpolynomial_fold *pwqp);
void isl_union_pw_qpolynomial_fold_free(
	__isl_take isl_union_pw_qpolynomial_fold *upwf);
__isl_give isl_union_pw_qpolynomial_fold *isl_union_pw_qpolynomial_fold_copy(
	__isl_keep isl_union_pw_qpolynomial_fold *upwf);

__isl_give isl_union_pw_qpolynomial_fold *isl_union_pw_qpolynomial_fold_fold(
	__isl_take isl_union_pw_qpolynomial_fold *upwf1,
	__isl_take isl_union_pw_qpolynomial_fold *upwf2);
__isl_give isl_union_pw_qpolynomial_fold *isl_union_pw_qpolynomial_fold_add_union_pw_qpolynomial(
	__isl_take isl_union_pw_qpolynomial_fold *upwf,
	__isl_take isl_union_pw_qpolynomial *upwqp);
__isl_give isl_union_pw_qpolynomial_fold *isl_union_pw_qpolynomial_fold_mul_isl_int(
	__isl_take isl_union_pw_qpolynomial_fold *upwf, isl_int v);

__isl_give isl_union_set *isl_union_pw_qpolynomial_fold_domain(
	__isl_take isl_union_pw_qpolynomial_fold *upwf);
__isl_give isl_union_pw_qpolynomial_fold *isl_union_pw_qpolynomial_fold_intersect_domain(
	__isl_take isl_union_pw_qpolynomial_fold *upwf,
	__isl_take isl_union_set *uset);

enum isl_fold isl_union_pw_qpolynomial_fold_get_type(
	__isl_keep isl_union_pw_qpolynomial_fold *upwf);
__isl_give isl_dim *isl_union_pw_qpolynomial_fold_get_dim(
	__isl_keep isl_union_pw_qpolynomial_fold *upwf);

__isl_give isl_qpolynomial *isl_union_pw_qpolynomial_fold_eval(
	__isl_take isl_union_pw_qpolynomial_fold *upwf,
	__isl_take isl_point *pnt);

__isl_give isl_union_pw_qpolynomial_fold *isl_union_pw_qpolynomial_fold_coalesce(
	__isl_take isl_union_pw_qpolynomial_fold *upwf);
__isl_give isl_union_pw_qpolynomial_fold *isl_union_pw_qpolynomial_fold_gist(
	__isl_take isl_union_pw_qpolynomial_fold *upwf,
	__isl_take isl_union_set *context);

__isl_give isl_union_pw_qpolynomial_fold *isl_union_pw_qpolynomial_fold_align_params(
	__isl_take isl_union_pw_qpolynomial_fold *upwf,
	__isl_take isl_dim *model);

int isl_union_pw_qpolynomial_fold_foreach_pw_qpolynomial_fold(
	__isl_keep isl_union_pw_qpolynomial_fold *upwf,
	int (*fn)(__isl_take isl_pw_qpolynomial_fold *pwf,
		    void *user), void *user);
__isl_give isl_pw_qpolynomial_fold *isl_union_pw_qpolynomial_fold_extract_pw_qpolynomial_fold(
	__isl_keep isl_union_pw_qpolynomial_fold *upwf, __isl_take isl_dim *dim);

__isl_give isl_printer *isl_printer_print_union_pw_qpolynomial_fold(
	__isl_take isl_printer *p,
	__isl_keep isl_union_pw_qpolynomial_fold *upwf);

__isl_give isl_union_pw_qpolynomial_fold *isl_union_pw_qpolynomial_bound(
	__isl_take isl_union_pw_qpolynomial *upwqp,
	enum isl_fold type, int *tight);
__isl_give isl_union_pw_qpolynomial_fold *isl_union_set_apply_union_pw_qpolynomial_fold(
	__isl_take isl_union_set *uset,
	__isl_take isl_union_pw_qpolynomial_fold *upwf, int *tight);
__isl_give isl_union_pw_qpolynomial_fold *isl_union_map_apply_union_pw_qpolynomial_fold(
	__isl_take isl_union_map *umap,
	__isl_take isl_union_pw_qpolynomial_fold *upwf, int *tight);

__isl_give isl_union_pw_qpolynomial *isl_union_pw_qpolynomial_to_polynomial(
	__isl_take isl_union_pw_qpolynomial *upwqp, int sign);

#if defined(__cplusplus)
}
#endif

#endif
