#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sum(const ll n, const ll a, const ll d){
    return (2*a + (n-1)*d)*n/2;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, X;
    ll L;
    cin >> N >> X >> L;
    vector<ll> a(N+5, 0), d(N+5, 0);
    for(ll i = 0; i < N; i++) cin >> a[i] >> d[i];


    if(X >= L){
        ll ans = 0;
        for(ll i = 0; i < N; i++){
            ll _a = a[i] + (X-1)*d[i];
            ll _d = -d[i];
            ans = max(ans, sum(L, _a, _d) );
        }
        cout << ans << endl;
        return 0;
    }

    ll bundle = L/X;
    ll bundle_rest = L%X;
    ll bundle_sum = 0;
    if(bundle_rest == 0){
      bundle--;
      bundle_rest = X;
    }


    // Init
    for(ll i = 0; i < bundle; i++){
        bundle_sum += sum(X, a[i], d[i]);
    }

    // Leftmost
    ll ans = 0;
    //cout << "A" << endl;
    //cout << bundle << endl;
    //cout << a.size() << endl;
    ans = bundle_sum + sum(bundle_rest, a.at(bundle), d.at(bundle));
    //cout << "B" << endl;

    // Between
    for(ll removing = 0; removing < N - bundle; removing++){
        ll local_ans = 0;
        ll adding = removing + bundle;
        bundle_sum -= sum(X, a.at(removing), d.at(removing));
        bundle_sum += sum(X, a.at(adding),   d.at(adding)  );

        ll left_a  = a.at(removing), left_d  = d.at(removing);

        if( removing != N - bundle - 1){
            ll right_a = a.at(adding+1), right_d = d.at(adding+1);

            // l: the number of terms used by right-side sequence.
            ll l = 0, r = bundle_rest;
            while(l+1 < r){
              ll mid = (l+r)/2;
              ll b_mid = right_a + mid * right_d;
              ll a_mid = left_a + (X - bundle_rest + mid) * left_d;
              //cout << a_mid << " " << b_mid << endl;
              if( b_mid - a_mid + (left_a - right_a) >= 0 ){
                l = mid;
              }else{
                r = mid;
              }
            }
            // l: the beginning of taking sum.
            ll left_begin = left_a + left_d*(X - bundle_rest + l + 1);
            //cout << "left_begin=" << left_begin << endl;
            ll left_num = bundle_rest - l - 1;
            ans = max(ans, bundle_sum + sum(left_num, left_begin, left_d) + sum(l+1, right_a, right_d));

            left_a = left_a + (X-1)*left_d;
            left_d = -left_d;
            ans = max(ans, bundle_sum + sum(bundle_rest, left_a, left_d));
        }else{
          left_a = left_a + (X-1)*left_d;
          left_d = -left_d;
          ans = max(ans, bundle_sum + sum(bundle_rest, left_a, left_d));
        }
    }

    // Rightmost
    /*
    cout << "A" << endl;
    cout << N-bundle-1 << endl;
    bundle_sum -= sum(X, a.at(N-bundle-1), d.at(N-bundle-1));
    cout << "b" << endl;
    bundle_sum += sum(X, a.at(N-1), d.at(N-1));
    cout << "c" << endl;
    //cout << a[N-1] + (X-1)*d[N-1] << endl;
    //cout << bundle_sum << endl;
    ans = max(ans, bundle_sum + sum(bundle_rest, a[N-bundle-1] + (X-1)*d[N-bundle-1], -d[N-bundle-1]));
    */

    cout << ans << endl;
    return 0;
}
