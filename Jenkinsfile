pipeline {
  agent any
  stages {
    stage('Print Test') {
      steps {
        echo 'HelloWorld'
      }
    }
    stage('Deb Build Test') {
      steps {
        sh 'fpm -s dir -t deb -n shell '
      }
    }
  }
}