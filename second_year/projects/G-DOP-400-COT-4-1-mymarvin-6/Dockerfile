FROM jenkins/jenkins:lts
USER root
ENV JAVA_OPTS="-Djenkins.install.runSetupWizard=false"
RUN jenkins-plugin-cli --plugins \
    job-dsl \
    configuration-as-code \
    role-strategy \
    git \
    workflow-aggregator
COPY my_marvin.yml /var/jenkins_home/casc.yaml
COPY job_dsl.groovy /var/jenkins_home/job_dsl.groovy
RUN chown -R jenkins:jenkins /var/jenkins_home
ENV CASC_JENKINS_CONFIG=/var/jenkins_home/casc.yaml
USER jenkins
EXPOSE 8080
EXPOSE 50000