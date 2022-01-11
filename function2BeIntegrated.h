

// HERE IS THE FUNCTION TO BE INTEGRATED

struct targetfunction{
        VecDoub CoxBeta;
        Doub t0;
        void Settargetfunction( VecDoub &CoxBeta, Doub &t0);
        Doub operator()(const Doub x);
} ;

//targetfunction::targetfunction() { }

void targetfunction::Settargetfunction( VecDoub &CoxBeta, Doub &t0 ) {
        CoxBeta = CoxBeta;
        t0 = t0;
}

Doub targetfunction::operator()(const Doub x) {
        // Does this have to return a vector?  Or can it just return Doub?
        // The target function will be evaluated at the point x

        Doub lambda = exp(CoxBeta[0]);
        Doub beta1 = CoxBeta[1];
        Doub beta2 = CoxBeta[2];
        Doub beta3 = CoxBeta[3];

        Doub thisnormaldens =
             (1.0/sqrt(2.0*(1/12.0)*M_PI)) * exp(-pow((x-0.5),2)/(2.0*(1/12.0)));

        Doub thisdifference =
             exp(-lambda*t0*exp(beta2+(beta1+beta3)*x)) - exp(-lambda*t0*exp(beta1*x));

        Doub myreturn = thisdifference * thisnormaldens;

        return myreturn;

}



