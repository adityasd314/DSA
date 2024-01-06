/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function(g, s) {
    let t = g.sort((b,a)=>b-a)
    let j = 0;
    s.sort((b,a)=>b-a).forEach((x, _)=>{
        (x >= t[j]) && j++;
    }, 0);
    return j
};