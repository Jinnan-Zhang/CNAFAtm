void buildprior(){

  TF1 *prior = new TF1("prior", "pow(x,-3)",2.0,4.31);
  prior->Draw();

}
