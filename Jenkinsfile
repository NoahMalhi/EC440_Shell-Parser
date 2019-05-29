pipeline {
  agent any
  stages {
    stage('Print Test') {
      steps {
        echo 'HelloWorld'
      }
    }
    stage('Deb Build Test') {
      parallel {
        stage('Deb Build Test') {
          steps {
            sh '''mkdir       
testFolder



'''
          }
        }
        stage('moveFiles') {
          steps {
            sh 'vi myshell.c'
          }
        }
      }
    }
  }
}