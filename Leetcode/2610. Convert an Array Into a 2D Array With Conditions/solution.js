/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var findMatrix = function (nums) {
    const result = {};
    let r = [[]];
    nums.forEach((num) => {
        if (result[num]){
            if (r.length < ++result[num]){
                r.push([])
                }
            else {
                result[num] = 1
                r[0].push(num)
            }}


    })
    for (key in result)
        for (let i = 1; i < result[key]; i++)
            r[i].push(key);
    return r;
};
