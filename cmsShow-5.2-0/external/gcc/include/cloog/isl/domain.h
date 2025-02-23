#ifndef CLOOG_ISL_DOMAIN_H
#define CLOOG_ISL_DOMAIN_H

#include <isl/map.h>
#include <isl/set.h>
#include <isl/union_map.h>
#include <isl/union_set.h>

#if defined(__cplusplus)
extern "C" 
  {
#endif 


struct cloogdomain {
};

struct cloogscattering {
};

CloogDomain *cloog_domain_from_isl_set(struct isl_set *set);
CloogScattering *cloog_scattering_from_isl_map(struct isl_map *map);
CloogUnionDomain *cloog_union_domain_from_isl_union_map(
	__isl_take isl_union_map *umap);
CloogUnionDomain *cloog_union_domain_from_isl_union_set(
	__isl_take isl_union_set *uset);

__isl_give isl_set *isl_set_from_cloog_domain(CloogDomain *domain);


#if defined(__cplusplus)
  }
#endif 
#endif /* define _H */
